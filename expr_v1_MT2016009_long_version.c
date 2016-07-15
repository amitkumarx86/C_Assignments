/*
 * C Program to Evaluate Expression without precedence
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
struct node
{
    char info;
    struct node *ptr;
}*top,*top1,*temp;
 
int topelement();
void push(int data);
char pop();
void display();
void stack_count();
void create();
int evaluate(char *exp, int value);
int computation(int value1, char operator, int val);
int count = 0;

void main()
{
	int value,i,j,length_of_exp;
	int result;
	char exp[500],c;
    create(); // create a stack
    printf("Enter the Expression:");
    scanf("%s",exp);
    
    
    while(1){
    	printf("Enter Data:");
    	scanf("%d",&value);
    	if(value == 1000) break;
    	result = evaluate(exp, value);
    	printf("result = %d\n", result);
    }
    
    
}
/*
void main(){
	char exp[]={'x','^','2','+','4','*','x','-','3'};
	printf("Result = %d\n",evaluate(exp, 4, 9));
}*/
// function to evaluate expression
int evaluate(char *exp, int value){
	int length_of_exp = strlen(exp);
	int i=0,temp,temp1,secondOperand,firstOperand;
	char var,var1,var2;
	int result;
	int compute[100], index;
	for(i=length_of_exp-1; i>=0; i--){
		if(exp[i] == ' '){
    		if(exp[i] == 'x' || exp[i] == 'y'){
    			if(value > 0) push(value+'0');
    			else
    				push((char)exp[i]);
    		}
    	    else
    			push((char)exp[i]);
       }
	}
    display();


	index=0;
	while(top->ptr != NULL)
    {
    	var1 = pop();

    	if(isdigit(var1)){
    		compute[index] = var1-'0';
    		//printf("compute= %d",compute[index]);
        }
        else if(var1 == 'x' || var1 == 'y'){
    		compute[index] = value;
    		//printf("compute2= %d",compute[index]);
		}
    	else{
    		    var2 = pop();
        	    if(isdigit(var2)){
        	    	//printf("\nIndex = %d\n",index);
        	    	
        	    	firstOperand = compute[index];
        	    	secondOperand= var2 - '0';
        	    }
				
			    else{
			    	firstOperand = compute[index];
			    	secondOperand = value;
			    }
        	    printf("computation, tmp = %d, var1 = %c, var 2= %d\n",firstOperand,var1,secondOperand );

        	    result = computation(firstOperand, var1, secondOperand);
    		    //printf("result= %d and index = %d\n",result,index);
    		    //push(result);
    		    index = index +1;
    		    compute[index] = result;
    		    //display();
    		    
    		    if(top == NULL) return result;
    	}
	    //display();
    }
	   //display();
       //printf("%d",compute[index]);
	   return result;
    
} 


// computation function 
 
int computation(int value1, char operator, int val){
int result;
int value2 = val;
switch (operator)
    {
    case '+':
        result =  value1 +  value2;
        break;
    case '-':
        result =  value1 -  value2;
        break;
    case '/':
        result =  value1 /  value2;
        break;
    case '*':
        result =  value1 *  value2;
        break;
    case '^':
        result = (int)pow(value1,value2);
        
        break; 
    }
return result;
}

/* Create empty stack */
void create()
{
    top = NULL;
}
 
/* Count stack elements */
void stack_count()
{
    printf("\n No. of elements in stack : %d", count);
}
 
/* Push data into stack */
void push(int data)
{
    if (top == NULL)
    {
        top =(struct node *)malloc(1*sizeof(struct node));
        top->ptr = NULL;
        top->info = data;
    }
    else
    {
        temp =(struct node *)malloc(1*sizeof(struct node));
        temp->ptr = top;
        temp->info = data;
        top = temp;
    }
    count++;
}
/* Display stack elements */
void display()
{
    top1 = top;
 
    if (top1 == NULL)
    {
        printf("Stack is empty");
        return;
    }
 
    while (top1 != NULL)
    {
        printf("%c ", top1->info);
        top1 = top1->ptr;
    }
 }
 /* Pop Operation on stack */
char pop()
{
	char value;
    top1 = top;
 
    if (top1 == NULL)
    {
        printf("\n Error : Trying to pop from empty stack");
        return;
    }
    else
        top1 = top1->ptr;
    
    value = top->info;
    free(top);
    top = top1;
    count--;
    return value;
}
/* Return top element */
int topelement()
{
    return(top->info);
}
 
 
 