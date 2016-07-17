#include<stdio.h>
int main(){
	char *arr[6];
	char temp[10];
	int i=0;
	for(;i<3;i++){
		printf("Enter the string = ");
		scanf("%s",temp);
		arr[i] = temp;
		printf("\n");
	}
	for(i=0;i<3;i++){
		printf("String is = %s\n",arr[i]);
	}

}