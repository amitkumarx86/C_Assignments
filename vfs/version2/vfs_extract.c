#include "vfs.h"
extern struct vfs_main vfs_m;

int vfs_extract(char *file_name_with_path){

	// variable declaration
	int no_of_files,i=0;
	int flag=0;
	int offSet = 0;
	int nextoffSet = 0;
	// check whether vfs is open or not
	if(vfs_m.vfs_status == 1){
		return VFS_NOT_CREATED;
	}

	no_of_files = vfs_m.header.vfs_info_data.no_of_files;
	while(i < no_of_files){
		#ifdef DEBUG
			printf("While started...\n");
		#endif
		if(strcmp(vfs_m.header.vfs_files[i].fname,file_name_with_path) == 0){
			flag=1;
			offSet = vfs_m.header.vfs_files[i].offset ;
			break;
		}
		else
			i++;
	}// while close
	if(flag == 0)
		return FILE_NOT_FOUND;
    
	// calculate file offset
	//nextoffSet   = vfs_m.header.vfs_files[i].file_size;
	
	int seekFlag = fseek(vfs_m.vfs_fp,offSet,SEEK_SET); 
	// return if seek failed
	if(seekFlag != 0){
		return FILE_SEEK_FAILED;
	}

	#ifdef DEBUG
		printf("offset = %d and filename = %s and read boundry = %d\n",offSet,file_name_with_path,offSet + vfs_m.header.vfs_files[i].file_size);
	#endif
	
	FILE *fp;
	//openning a external file using it's path
	fp=fopen(file_name_with_path,"w");

	if(fp == NULL){
		return EXTERNAL_FILE_NOT_CREATED;
	}

	
	char *buffer;
	buffer = (char *)malloc(vfs_m.header.vfs_files[i].file_size);
	fread(buffer, vfs_m.header.vfs_files[i].file_size, 1, vfs_m.vfs_fp); // reading from vfs
	fwrite(buffer , vfs_m.header.vfs_files[i].file_size , 1 , fp ); // writing into external file
    #ifdef DEBUG
    	printf("Data = %s\n",buffer);
    #endif
	fclose(fp); // close external file
    free(buffer); // release mem

    return FILE_EXTRACT_SUCCESS;
}