/*
 * C Program to Evaluate Expression without precedence
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "evaluation.h" 

int main(){
    char exp[100];
    int value;
    printf("Expression P(x)= ");
    scanf("%s",exp);
    while(1){
    	printf("Enter Value= ");
    	scanf("%d",&value);
    	if(value == 1000) break;
    	printf("Result = %f\n",evaluation(exp,value));
    }
}

