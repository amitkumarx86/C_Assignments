#include <stdio.h>
#include "change_maker.h"
#define MAXSIZE 100

int main(){
	
	char *denomination, result[MAXSIZE], choice='y';
	int amount;
	int running=1;
	/*
	printf("Enter Denomination Order = ");
	scanf("%s",denomination);
	while(running){
		printf("Enter amount = ");
		scanf("%d",&amount);
		
		__optimal_change_maker(denomination,amount);
		
		printf("Press 1 to continue...");
		scanf("%d",&running);
		
	}
	*/
	
	
	denomination="20,15,7,1";
	amount = 123;
	__optimal_change_maker(denomination,amount);
}