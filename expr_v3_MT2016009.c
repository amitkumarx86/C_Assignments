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
float evaluate(char *exp, int value);
float computation(float value1, char operator, float val);
char* infix_to_postfix(char *exp);
int priority(char a, char b);
int count = 0;
char postfix[100];

/*
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
    
    
}*/

void main(){
	//char exp[]={'(','2','-','3',')','^','4','-','(','5','-','6',')','+','3','-','(','(','4','+','5',')','+','9',')'};
    char exp[]={'(','x','-','2','*','x',')','^','3','-','(','x','-','3',')'};
    float t = evaluate(exp, -1);
    printf("Result = %3.2f\n",t);
}
// function to evaluate expression
float evaluate(char *exp, int value){
	int exp_length = strlen(exp);
    //evaluate postfix function
    infix_to_postfix(exp);
    //printf("%s\n",postfix);
    int i=0,to=-1;
    float result;
    float arr[100];
    int length = strlen(postfix);
    while(length > 0){
        if(postfix[i] =='+' || postfix[i] =='-' || postfix[i] =='*' || postfix[i] =='/' || postfix[i] =='^'){
            float secondOperand=arr[to--];
            float firstOperand=arr[to--];
            char operator=postfix[i];
            result = computation(firstOperand,operator,secondOperand);
            //printf("result%f\n",result);
            arr[++to] = result;
            i++;     
        }
        else{
            if(postfix[i] == 'x' || postfix[i] == 'y') arr[++to]= value;
            else  arr[++to] = postfix[i] - '0';
            i++; 
        }
        length--;
    }
    return arr[to];
}


char* infix_to_postfix(char *exp){
    int i=0,index=0;
    
    while(exp[i] != '\0'){
        if(exp[i] != ' '){ // check for extra spaces
            if(exp[i] == '('){
                #ifdef DEBUG
                   printf("Push char = %c\n",exp[i]);
                #endif
                push(exp[i]);
            }
            else if(isdigit(exp[i]) || exp[i] == 'x' || exp[i] == 'y')
            {  
                #ifdef DEBUG
                   printf("digit = %d\n",exp[i]-'0');
                #endif
                postfix[index++] = exp[i]; 
            }
            else if(exp[i] == ')'){
                char temp = pop();
                #ifdef DEBUG
                   printf("Popped Data = %c\n",temp);
                #endif
                while(temp != '('){
                    postfix[index++] = temp; 
                    temp = pop();
                    #ifdef DEBUG
                     printf("Popped Data123 = %c\n",temp);
                    #endif
                    //if(top != NULL) temp = pop();
                }
            }
            else{
                if(top == NULL) {
                    push(exp[i]); 
                    #ifdef DEBUG
                       printf("Push operator345 = %c\n",exp[i]);
                    #endif
                }
                if(top != NULL) {
                    if(priority(top->info,exp[i]) <= 0 ){
                        push(exp[i]); 
                        #ifdef DEBUG
                                printf("\nPrioio = %d, var 1=%c, var2 = %c \n",priority(top->info,exp[i]),top->info,exp[i]);
                                //printf("Popped Data5 = %c\n",var1);
                                int k=0;
                                /*
                                for(;k<index;k++){
                                    printf("%c",postfix[k]);
                                }*/
                            #endif
                    }
                    else{
                        char var2 = exp[i];
                        char var1 = top->info;

                        while(priority(var1,var2) > 0  && top != NULL){
                            if(top == NULL) break;
                            var1 = pop();
                            pop();
                            postfix[index++] = var1;
                            #ifdef DEBUG
                                printf("\nPrioio = %d, var 1=%c, var2 = %c \n",priority(var1,var2),var1,var2);
                                printf("Popped Data5 = %c\n",var1);
                                int k=0;
                                for(;k<index;k++){
                                    printf("%c",postfix[k]);
                                }
                            #endif
                            
                        }
                        push(exp[i]); 

                    }
                     
                }
            }
            i++;
            //display();
        }
    } // while loop ends
    char remaining;
    //display();
    while(top != NULL){
        remaining = pop();
        postfix[index++] = remaining;
    }
    int k=0;
    /*
    for(k=0;k<index;k++){
        printf("%c",postfix[k]);
    }
    */
    
}
// function to check priority
int priority(char a, char b){
    if(a == '*' && (b == '+' || b == '-')){
        return 1;
    }
    else if(a == '/' && (b == '+' || b == '-')){
        return 1;
    }
    else if(a == '^' && (b == '+' || b == '-' || b == '*' || b == '/')){
        return 1;
    }
    else if(a == '/' && (b == '+' || b == '-')){
        return 1;
    }
    else if((a == '*' && b == '/') || (a == '*' && b == '/')){
        return 0;
    }
    else if(a == '/' && b == '*'){
        return 0;
    }
    else if((a == '+' && b == '-') || (a == '-' && b == '+')){
        return 0;
    }
    else if((a == '+' && b == '+') || (a == '-' && b == '-') || (a == '*' && b == '*') || (a == '/' && b == '/') || (a == '^' && b == '^') ){
        return 0;
    }
    else if(a == '(')
        return 0;
    else
        return -1;
    
    
       
}
// computation function 
 
float computation(float value1, char operator, float val){
float result;
float value2 = val;
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
        result = (float)pow(value1,value2);
        
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
 
 
 