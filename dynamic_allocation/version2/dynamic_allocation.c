#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 6

int main(){
	char *arr[MAX_SIZE];
	char *str;
	char c;
  	int i = 0, j = 1,k=0;;

  	

	for(k=0;k<6;k++){
		j=1;
		i=0;
		c=0;
		printf("Enter the string = ");
		str = (char*)malloc(sizeof(char));
		while (c != '\n') {
		    // read the input from keyboard standard input
		    c = getc(stdin);

		    // re-allocate (resize) memory for character read to be stored
		    str = (char*)realloc(str, j * sizeof(char));

		    // store read character by making pointer point to c
		    str[i] = c;
		    j++;
		    i++;
		} // while close
	  str[i] = '\0';
	  //printf("\n");
	  arr[k]=str;
	  //free(str);
	}// for close
	
	//free(str);
	printf("---------Output---------\n");
	for(i=0;i<6;i++){
		printf("String is %d = %s",i+1,arr[i]);
	}
}