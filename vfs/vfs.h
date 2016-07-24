#ifndef vfs    // include guards
#define vfs
	#include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
	#include <libgen.h>
	#include <ctype.h>
    #define MAX_LEN 30
	#define MAX_FILES 100
	#define VFS_OPEN 0
    #define VFS_CLOSE 1
    #define VFS_CREATED 101
	#define VFS_NOT_CREATED 102
	#define FILE_NOT_FOUND 103
	#define FILE_SEEK_FAILED 104
	#define FILE_SAVED 105
	#define FILE_EXTRACT_SUCCESS 106
	#define DEUPLICATE_FILE_NAME 107
	#define VFS_NOT_OPENED 108
	#define EXTERNAL_FILE_SIZE_ZERO 109
	#define EXTERNAL_FILE_NOT_CREATED 110
	// file info
	struct vfs_file_info{
		char fname[MAX_LEN];
		int offset;
	};
	// vfs header (w/o file info)
	struct vfs_info{
		char vfs_name[MAX_LEN];
		int no_of_files;
		int size;
	};
	// complete header
	struct vfs_header_info{
		struct vfs_info vfs_info_data;
		struct vfs_file_info vfs_files[MAX_FILES];  
	};
	// vfs tracker
	struct vfs_main{
		struct vfs_header_info header;
		FILE *vfs_fp;
		int vfs_status;
	};

	int vfs_create(char *name_with_path);
	int vfs_open(char *name_with_path );
	int vfs_save(char *file_to_save);
	int vfs_extract(char *name_with_path);
	int vfs_close();
	
#endif
