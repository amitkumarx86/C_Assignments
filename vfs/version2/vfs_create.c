#include "vfs.h"
/*
int main(){
	char name_with_path[30] = "my_vfs";
	int return_code = vfs_create(name_with_path);	
	printf("%d\n",return_code);
}
*/
extern struct vfs_header_info header_info;
int vfs_create(char *name_with_path){
	FILE *fp;
	//struct vfs_header_info header_info;
	
	
	// creating vfs file 
	fp = fopen(name_with_path, "rb+");
	if(fp == NULL){
		fp = fopen(name_with_path, "wb+");
			if(fp == NULL){
				return VFS_NOT_CREATED;
			}
					// initializing vfs with header data
			strcpy(header_info.vfs_info_data.vfs_name, name_with_path);
			header_info.vfs_info_data.no_of_files         = 0;
			header_info.vfs_info_data.size                = sizeof(header_info);
			header_info.vfs_files[0].offset = sizeof(header_info);
			header_info.vfs_files[0].file_size = 0;
			// writing header info into vfs
			#ifdef DEBUG
				printf("Name = %s, no_of_files = %d, Header Size = %d and offset = %d\n",header_info.vfs_info_data.vfs_name,header_info.vfs_info_data.no_of_files,header_info.vfs_info_data.size,header_info.vfs_files[0].offset);
			#endif
			fwrite(&header_info ,  sizeof(header_info), 1 , fp );
	}
	
	
	fclose(fp);
    // returning status code
    return VFS_CREATED;
}