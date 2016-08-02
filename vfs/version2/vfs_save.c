#include "vfs.h"
extern struct vfs_header_info header_info;
extern struct vfs_main vfs_m;
int vfs_save(char *file_name_with_path){
	FILE *fp;
	//openning a external file using it's path
	fp=fopen(file_name_with_path,"r");
	
    if(fp == NULL){
    	return FILE_NOT_FOUND;
    }

	char *basec, *file_to_save;

	basec = strdup(file_name_with_path);
	file_to_save = basename(basec);
    // check whether vfs is open or not
	if(vfs_m.vfs_status == 1){
		return VFS_NOT_CREATED;
	}

    //check for duplicate file name
    int no_of_files = vfs_m.header.vfs_info_data.no_of_files;
	int i=0;
	while(i < no_of_files){
		if(strcmp(vfs_m.header.vfs_files[i++].fname,file_to_save) == 0){
			return DEUPLICATE_FILE_NAME;
		}
	}// while close
	

	//finding file size of external file
	int fsize=0;	
	fseek(fp,0,SEEK_END);
	fsize=ftell(fp);

	if(fsize == 0){
		return EXTERNAL_FILE_SIZE_ZERO;
	}
	
	char *tempData;
	tempData=(char*)malloc(fsize);
	
	fseek(fp,0,SEEK_SET);
	fread(tempData,fsize,1,fp);
	
	#ifdef VERBOSE
	    printf("Fsize = %d\n",fsize );
		printf("Buffer = %s and buffr size = %d\n",tempData, sizeof(tempData));
	#endif
	//fclose(fp); // closed external file
	// first seek location to write file
	int offset = 0;
	if(vfs_m.header.vfs_info_data.no_of_files == 0)
		offset =  vfs_m.header.vfs_files[0].offset +1;
	else		
		offset = vfs_m.header.vfs_files[vfs_m.header.vfs_info_data.no_of_files-1].file_size + vfs_m.header.vfs_files[vfs_m.header.vfs_info_data.no_of_files-1].offset+1;
		

	#ifdef VERBOSE
		printf("Offset = %d\n",offset );
		//printf("Buffer = %s and buffr size = %d\n",buffer, sizeof(buffer));
	#endif
	

	// writing data to vfs
	fseek(vfs_m.vfs_fp,offset,SEEK_SET);
	fwrite(tempData, fsize ,1,vfs_m.vfs_fp);
 	fseek(vfs_m.vfs_fp,0,SEEK_SET);
	
	
	vfs_m.header.vfs_info_data.no_of_files++;  // increment file count

	if(vfs_m.header.vfs_info_data.no_of_files != 0)
		vfs_m.header.vfs_files[vfs_m.header.vfs_info_data.no_of_files-1].offset=offset;

 	vfs_m.header.vfs_files[vfs_m.header.vfs_info_data.no_of_files-1].file_size = fsize; // set file size
 	strcpy(vfs_m.header.vfs_files[vfs_m.header.vfs_info_data.no_of_files-1].fname,file_to_save);

	#ifdef VERBOSE
		printf("Size of exter file = %d\n",fsize );
		printf("Name = %s, no_of_files = %d, Header Size = %d and offset = %d and name of extern file = %s\n",
			vfs_m.header.vfs_info_data.vfs_name,
			vfs_m.header.vfs_info_data.no_of_files,
			vfs_m.header.vfs_info_data.size,
			vfs_m.header.vfs_files[vfs_m.header.vfs_info_data.no_of_files-1].offset,
			vfs_m.header.vfs_files[vfs_m.header.vfs_info_data.no_of_files-1].fname);
	#endif

	free(tempData); //release mem
	fclose(fp); // closing external file
	return FILE_SAVED;
}