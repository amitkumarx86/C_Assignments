#include<stdio.h>
#include<string.h>
void main()
{
  char a[100];
  char b[100];
  int c[100];
  int i=0,j=0,sum,carry=0,k,l;
  int a_len=0;
  int b_len=0;
  char temp;
  printf("Length of first number = ");
  scanf("%d",&a_len);
  printf("\nLength of second number = ");
  scanf("%d",&b_len);
  printf("\nFirst number = ");
  scanf("%s",a);
  printf("\nSecond number = ");
  scanf("%s",b);
  // for equal length

  if(a_len == b_len){
    for(i=a_len-1; i>=0;i--){
       sum=0;
       sum = carry+(a[i] - '0') + (b[i] - '0');
       if(sum > 10)
             carry=sum / 10; 
             sum=sum %10; 
       c[i]=sum;
    }
    printf("Sum = ");
    for(i=0; i<a_len; i++)
    {
       printf("%d",c[i ]);   
    }
    printf("\n");
    
  } // if close
  //for a_len > b_len
  
  else if(a_len > b_len)
  {
    carry=0;
    k=a_len;
    //printf("%s\n","inside a_len > b_len" );
    for(j=b_len-1,l=a_len-1; j>=0;j--,l--){
       sum=0;
       sum = carry+ (a[j+a_len-b_len] - '0') + (b[j] - '0');
             
       if(sum > 10)
             carry=sum / 10; 
             sum=sum % 10; 
       //printf("sum=%d\n",sum);
       k=k-1;
       c[k]=sum;
       //printf("k= %d,sum=%d,carry=%d\n",k,c[k],carry);
    }

    //printf("%s\n","inside a_len > b_len : first for lop" );
    
    for(i=l; i>=0; i--){
      sum=0; 
      sum = carry+(a[i] - '0');
       if(sum > 10)
             carry=sum / 10; 
             sum=sum %10; 
       k=k-1;
       c[k]=sum;
       //printf("%d\n",sum);
       //printf("k= %d,sum=%d,carry=%d\n",k,c[k],carry);
       carry=0; // carray not required
    }
    
    printf("Sum = ");
    for(i=0; i<a_len; i++)
    {
       printf("%d",c[i ]);   
    }
    printf("\n");
    
    //printf("\n");
  } // second if
  
  else
  {   // if a_len < b_len
    carry=0;
    k=b_len;
    //printf("%s\n","inside a_len < b_len" );
    for(j=a_len-1,l=b_len-1; j>=0;j--,l--){
       sum=0;
       sum = carry+ (b[j+b_len-a_len] - '0') + (a[j] - '0');
             
       if(sum > 10)
             carry=sum / 10; 
             sum=sum % 10; 
       //printf("sum=%d\n",sum);
       k=k-1;
       c[k]=sum;
       //printf("k= %d,sum=%d,carry=%d\n",k,c[k],carry);
    }

      printf("%s\n","inside a_len > b_len : first for lop" );
    
    for(i=l; i>=0; i--){
      sum=0; 
      sum = carry+(b[i] - '0');
       if(sum > 10)
             carry=sum / 10; 
             sum=sum %10; 
       k=k-1;
       c[k]=sum;
       //printf("%d\n",sum);
       //printf("k= %d,sum=%d,carry=%d\n",k,c[k],carry);
       carry=0; // carray not required
    }
    
    printf("Sum = ");
    for(i=0; i<b_len; i++)
    {
       printf("%d",c[i ]);   
    }
    printf("\n");
    
  }
  
}
