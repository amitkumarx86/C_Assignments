#include "vfs.h"
struct vfs_header_info header_info;
struct vfs_main vfs_m;
int main(int argc, char *args[]){
  
  int RC=0;
  char name_with_path[30] = "my_vfs";
  //printf("%d\n",argc );
  //printf("%s\n",args[1] );
  if(argc > 3 || argc < 2){ // means two args
  	printf("Incorrect arguments..\n"); return 0;}

  if(argc == 2){
  	if(!(strcmp(args[1],"create") == 0 || strcmp(args[1],"open") ==0 || strcmp(args[1],"close") ==0)){
  		printf("Incorrect arguments.\n");
  		return 0;
  	}
  	else{
  		if(strcmp(args[1],"create") == 0){
  			RC = vfs_create(name_with_path);
			if(RC != VFS_CREATED){
				return VFS_NOT_CREATED;
			}
			//printf("vfs created successfully...\n");
  		}
  		else if(strcmp(args[1],"open") == 0){
  			RC = vfs_open(name_with_path);
			if(RC != VFS_OPEN){
				return VFS_NOT_OPENED;
			}
  		}
  		else if(strcmp(args[1],"close") == 0){
  			RC = vfs_close(name_with_path);
			if(RC != VFS_OPEN){
				return VFS_NOT_OPENED;
			}
  		}
  		return 0;
  	}
  }
  if(argc == 3){
  	if(strcmp(args[1],"save") == 0){
  		
  		RC = vfs_open(name_with_path);
		 
		if(RC != VFS_OPEN)
			return VFS_NOT_CREATED;

	    RC = vfs_save(args[2]);  // calling function to save
		if(RC == FILE_NOT_FOUND){
					printf("File not found, try again...\n");
					return FILE_NOT_FOUND;
		}
		else if(RC == VFS_NOT_CREATED){
			printf("First create vfs..\n");
			printf("Exiting..\n");
			return VFS_NOT_CREATED;
		 
		}
		else if(RC == DEUPLICATE_FILE_NAME){
			printf("File Name already exists, choose another one..\n");
			return DEUPLICATE_FILE_NAME;
		}
		else if(RC == EXTERNAL_FILE_SIZE_ZERO){
			printf("File size is 0\n");	
			return EXTERNAL_FILE_SIZE_ZERO;
		}
		RC = vfs_close(name_with_path);
		printf("File %s is saved successfully..\n",args[1]);
  	}
  	else if(strcmp(args[1],"extract") == 0){
  		RC = vfs_open(name_with_path);
		if(RC != VFS_OPEN)
			return VFS_NOT_CREATED;
  		char *basec, *file_to_save;
		basec = strdup(args[2]);
		file_to_save = basename(basec);
  		RC = vfs_extract(file_to_save);  // calling function to save
		if(RC == VFS_NOT_CREATED){
			printf("First create vfs..\n");
			return VFS_NOT_CREATED;
		}
		else if(RC == FILE_SEEK_FAILED){
			printf("File seel failed..\n");
			return FILE_SEEK_FAILED;
		}
		else if(RC == FILE_NOT_FOUND){
			printf("File Name does't exist, choose correct one..\n");
			return FILE_NOT_FOUND;
		}
		RC = vfs_close(name_with_path);
		printf("file %s is extracted successfully, check in Current Directory\n",file_to_save);
  	}
  	else{
  		printf("Incorrect command.\n");
  	}

  }
  	
    return 0;
}