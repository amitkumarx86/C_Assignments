#include "vfs.h"
//
/*
int main(){
	char name[30] = "my_vfs";
	vfs_open(name);	
}
*/
extern struct vfs_header_info header_info;
extern struct vfs_main vfs_m;


int vfs_open(char *name_with_path ){
	FILE *fp;
	int i=0;
	
	//struct vfs_main vfs_m;
	
	// check whether vfs is created or not
	fp = fopen(name_with_path, "rb+");
	if(fp == NULL){
		return VFS_NOT_CREATED;
	}

	fseek(fp,0,SEEK_SET);
	fread(&header_info,sizeof(header_info),1,fp);
	fseek(fp,0,SEEK_SET); // setting pointer to start after performing read operation
	
	#ifdef DEBUG
		printf("Name = %s, no_of_files = %d, Header Size = %d and offset = %d\n",
			header_info.vfs_info_data.vfs_name,
			header_info.vfs_info_data.no_of_files,
			header_info.vfs_info_data.size,
			header_info.vfs_files[0].offset);
	#endif

	vfs_m.header=header_info;
	vfs_m.vfs_fp = fp;
	//loading vfs_file_info

	for(i=0; i < vfs_m.header.vfs_info_data.no_of_files ;i++)
	{

		strcpy(vfs_m.header.vfs_files[i].fname,header_info.vfs_files[i].fname);
		vfs_m.header.vfs_files[i].offset=header_info.vfs_files[i].offset;
		#ifdef DEBUG
			//printf("%s\n", );
		#endif

	}

	//initializing vfs_main
	vfs_m.vfs_status=VFS_OPEN;
	#ifdef DEBUG
		printf("Name = %s, no_of_files = %d, Header Size = %d and offset = %d\n",
			vfs_m.header.vfs_info_data.vfs_name,
			vfs_m.header.vfs_info_data.no_of_files,
			vfs_m.header.vfs_info_data.size,
			vfs_m.header.vfs_files[0].offset);
	#endif

	fp=NULL;
return VFS_OPEN;
}
