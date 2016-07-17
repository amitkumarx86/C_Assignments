#include <stdio.h>
#include "change_maker.h"
#define MAXSIZE 100
int main(){
	
	char *denomination, result[MAXSIZE], choice='y';
	int amount;
	/*
	
	printf("Enter Denomination Order");
	scanf("%s",denomination);
	while(choice == 'Y' || choice == 'y'){
		printf("Enter amount");
		scanf("%d",&amount);
		result = change_maker(denomination,amount);
		printf("%s\n",result);
		printf("Press y to continue...");
		choice=getch();
		getch(); // to eat newline
	}
	*/
	denomination="500,100,50,20,10,5,1";
	amount = 5383;
	change_maker(denomination,amount);
}