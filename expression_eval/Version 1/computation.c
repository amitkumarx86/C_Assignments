#include <math.h>
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