#include "vfs.h"
extern struct vfs_main vfs_m;
/*
int main(){
	char name_with_path[30] = "my_vfs";
	int return_code = vfs_create(name_with_path,0);	
	printf("%d\n",return_code);
}
*/
int vfs_close(){
	
	// setting file pointer to start position
	fseek(vfs_m.vfs_fp, 0, SEEK_SET );
	// write data in vfs
	#ifdef DEBUG
		printf("Size of %d\n",sizeof(vfs_m.header));
		printf("No files = %d\n",vfs_m.header.vfs_info_data.no_of_files );
		printf("Name of files = %s\n",vfs_m.header.vfs_files[0].fname );
	#endif

	fwrite(&vfs_m.header , sizeof(vfs_m.header),1, vfs_m.vfs_fp);
	struct vfs_header_info header_info1;
	fseek(vfs_m.vfs_fp, 0, SEEK_SET );
	fread(&header_info1,sizeof(header_info1),1,vfs_m.vfs_fp);
	#ifdef DEBUG
		printf("vfs_close()\n");
		printf("Name = %s, no_of_files = %d, Header Size = %d and offset = %d and fname = %s\n",
			header_info1.vfs_info_data.vfs_name,
			header_info1.vfs_info_data.no_of_files,
			header_info1.vfs_info_data.size,
			header_info1.vfs_files[0].offset,
			header_info1.vfs_files[0].fname);
	#endif
	fclose(vfs_m.vfs_fp); // closing vfs

	// unsetting structure vfs
	
	vfs_m.vfs_status = 1;

    return VFS_CLOSE;
}