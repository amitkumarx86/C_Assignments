/*
 * Evaluate Expression without precedence
 */
#include <stdio.h>
#include <string.h>
#include "computation.h"
//float computation(float firstOperand, char operator, float secondOperand);
float subFunction(int valueOFVariable);
int length=0;
int i=0;
float num1,num2, number ,result;
char temp, operator;
float array_store[100];
int index=-1;
float evaluation(char *exp1,int valueOFVariable){
	//define variables
char exp[] = {'(','3','^','2',')','+','4','*','(','3','-','3',')'};
    
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
		if(temp == '('){
			result = subFunction(valueOFVariable);
			array_store[++index] = result;
		}

		printf("\nResult after paran loop = %f, exp[i] = %c",array_store[index],exp[i]);
        
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
			else if(isdigit(exp[i]) == '('){
				num2 = subFunction(valueOFVariable);
				//array_store[++index] = result;
			}
        	if(array_store[index]){
				num1 = array_store[index--];
			}
			#ifdef DEBUG
					printf("\nnum1 = %f, operator = %c, num2 = %f",num1,operator,num2);
			#endif
			result = computation(num1, operator, num2);
			array_store[++index] = result;
			//printf("%f, index = %d\n",result,index);
		}//else close

	}//while close
	return array_store[index];
}

float subFunction(int valueOFVariable){
	while(exp[i] != ')'){
				num1=0;
				num2=0;
				temp = exp[i];
				i++; length--;
				#ifdef DEBUG
					printf("\nUnder while temp = %c",temp);
				#endif

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

				 
				#ifdef DEBUG
					printf("\nAfter while exp = %c",exp[i]);
				#endif
			}
			i++;
			length--;
			temp = exp[i];
			i++;
			length--;


return array_store[index];
}


