/*
 * Evaluate Expression without precedence
 */
#include <stdio.h>
#include <string.h>
#include "computation.h"
float computation(float firstOperand, char operator, float secondOperand);
float evaluation(char *exp,int valueOFVariable){
	//define variables
    //char exp[] = {' ','x',' ','^','2','+','4','*','x','-','3'};
	int length=0;
	int i=0;
	float num1,num2, number ,result;
	char temp, operator;
	float array_store[100];
	int index=-1;
	length =strlen(exp);
	while(length > 0){
		if(exp[i]==' '){  // to avoid space
			i++;length--;
			continue;
		}
		num1=0;
		num2=0;
		temp = exp[i];
		i++; length--;
		if(isdigit(temp) || temp == 'x' || temp == 'y'){
			if(temp == 'x' || temp == 'y')    
				num1 = valueOFVariable;
			else
				num1 = temp - '0';
			length--;
			while(isdigit(exp[i])){
				number = exp[i] - '0';
				num1 = num1 * 10 + number;
				length--;
				i++;
			}// to get whole number
			array_store[++index] = num1;
		}// if close
		else{
			operator=temp;
			if(isdigit(exp[i]) || exp[i] == 'x' || exp[i] == 'y') {
				if(exp[i] == 'x' || exp[i] == 'y')    
					num2 = valueOFVariable;
				else
					num2 = exp[i] - '0';
				length--;
				i=i+1;
				while(isdigit(exp[i])){
					number = exp[i] - '0';
					num2 = num2 * 10 + number;
					length--;
					i++;
				}// to get whole number
			}// if close
        	if(array_store[index]){
				num1 = array_store[index--];
			}
			result = computation(num1, operator, num2);
			array_store[++index] = result;
			//printf("%f, index = %d\n",result,index);
		}//else close
	}//while close
	return array_store[index];
}


