#include "vfs.h"
struct vfs_header_info header_info;
struct vfs_main vfs_m;


int main(){
	char name_with_path[30] = "my_vfs";
	printf("Welcome to vfs...\n");
	printf("Creating vfs...\n");
	int RC = vfs_create(name_with_path);

	if(RC != VFS_CREATED){
		return VFS_NOT_CREATED;
	}
	printf("vfs created successfully...\n");
	
	printf("vfs loading...\n");
	RC = vfs_open(name_with_path);
	
	if(RC != VFS_OPEN){
		return VFS_NOT_OPENED;
	}
	printf("vfs loaded successfully...\n");
	
	int vfs_choice=1;
	
	
	char file_name_with_path[30];

	while(1){
		printf("Following operations available on vfs\n");
		printf("1. Save external file in vfs\n");
		printf("2. Extract external file in vfs\n");
		printf("3. Close vfs (program will end)\n");
		
		printf("Enter your choice = ");
		scanf("%d",&vfs_choice);
		
		//printf("\n");
		switch(vfs_choice){
			case 1:
				printf("Enter external file path = ");
				scanf("%s",file_name_with_path);
				RC = vfs_save(file_name_with_path);  // calling function to save
				if(RC == FILE_NOT_FOUND){
					printf("File not found, try again...\n");
					break;
				}
				else if(RC == VFS_NOT_CREATED){
					printf("First create vfs..\n");
					printf("Exiting..\n");
					return VFS_NOT_CREATED;
					break;
				}
				else if(RC == DEUPLICATE_FILE_NAME){
					printf("File Name already exists, choose another one..\n");
					break;
				}
				else if(RC == EXTERNAL_FILE_SIZE_ZERO){
					printf("File size is 0\n");	
					break;
				}
				printf("File %s is saved successfully..\n",file_name_with_path);
				break;
			case 2:
				printf("Enter file name (Excluding path) = ");
				scanf("%s",file_name_with_path);
				RC = vfs_extract(file_name_with_path);  // calling function to save
				if(RC == VFS_NOT_CREATED){
					printf("First create vfs..\n");
					printf("Exiting..\n");
					break;
				}
				else if(RC == FILE_SEEK_FAILED){
					printf("File seel failed..\n");
					break;
				}
				else if(RC == FILE_NOT_FOUND){
					printf("File Name does't exist, choose correct one..\n");
					break;
				}
				printf("File %s is extracted successfully, See it in Current Directory\n",file_name_with_path);
				break;
			case 3:
				printf("Closing vfs...\n");
				RC = vfs_close(name_with_path);
				if(RC = VFS_CLOSE){
					printf("Closed vfs successfully..\n");
					return 0;
				}
				printf("Unable to close vfs..\n");
				break;
			default:
				printf("Please enter a valid choice..\n");
				
		}// switch close
		printf("\n");
	}// while close	
	

}