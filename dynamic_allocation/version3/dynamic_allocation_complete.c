#include<stdio.h>
#include<stdlib.h>
int main(){
	char **arr,*str,c;
	int i = 0, j = 1,k=0,l=0;

  	int count =10;
	arr = (char**)malloc(sizeof(char));
    char choice='z'; 	
	while(choice == 'z'){
  		
    	arr[k] = (char*)malloc(sizeof(char));
    	
        i = 0;
		j=1;
		c='0';
    	str = (char*)malloc(sizeof(char));
		printf("Enter the string = ");
    	while (c != '\n') {
		    // read the input from keyboard standard input
		    c = getc(stdin);

		    // re-allocate (resize) memory for character
		    str = (char*)realloc(str, j * sizeof(char));
            str[i] = c;
		    j++;
		    i++;
		} // while close
	  
	    str[i] = '\0';
	    
	    arr[k] = str;
	    #ifdef DEBUG
	    	printf("String is = %s",arr[k]);
	    #endif
	    k++;
	    
	    printf("Press z to contnue...");
	    choice = getchar();
	    getchar();
	    //printf("Choice = %c",choice);
		printf("\n");
		arr = (char**)realloc(arr,(k+1)*sizeof(char));
	} // while close
	//free(str);
	printf("---------Output---------\n");
	for(i=0;i<k;i++){
		printf("String is %d = %s",i+1,arr[i]);
	}
}