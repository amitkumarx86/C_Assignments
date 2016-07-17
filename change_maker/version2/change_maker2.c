#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void displayArr(int index);
void change_maker_subprocess(char *denomination, int amount, int index);

int parseInput(char *denomination);
	
int arr[10][10];
void __change_maker(){
	char *denomination;
	denomination="500:5,100:3,50:6,20:8,10:10,5:10,1:100";
	char choice='y';
	int amount, index=0;
	
	
	//printf("Enter Denomination Order");
	//scanf("%s",denomination);
	index = parseInput(denomination);
	int running = 1;	
	while(running){
		printf("Enter amount = ");
		scanf("%d",&amount);
	
		
		change_maker_subprocess(denomination,amount,index);
		
		printf("Press any key to stop, 1 to contnue = ");
		scanf("%d",&running);
		//char temp = getchar(); // to eat newline
	}
	
	
}
void change_maker_subprocess(char *denomination, int amount, int index){

	int length = strlen(denomination);
	int i=0;
	//int index=0;
	#ifdef VERBOSE
		printf("denomination = %s\n",denomination );
	#endif
	// input read module
	
	int temp=0,currencyCount=0,k=0;
	// logic
	int count=10;
	while(amount != 0){
		
		for(i=0; i < index;i++){
			#ifdef DEBUG
				printf("amount = %d, arr = %d\n",amount,arr[i][0] );
			#endif
			if(amount >= arr[i][0] && arr[i][1] > 0){
				temp = amount / arr[i][0] ;
				#ifdef DEBUG
					printf("Temp = %d\n",temp);
				#endif
				if(arr[i][1] >= temp){
					arr[i][1] = arr[i][1] - temp;
					currencyCount = amount / arr[i][0] ;
					amount = amount % arr[i][0];
					#ifdef DEBUG
				    printf("Inside if amount = %d, arr = %d, freq = %d\n",amount,arr[i][0],arr[i][1] );
			        #endif
			    }
			    else{
			    	temp = (amount - (arr[i][0] * arr[i][1])) ;
			    	
					currencyCount = arr[i][1] ;
					arr[i][1] = 0;
					amount = temp;
					#ifdef DEBUG
				    printf("Inside else amount = %d, arr = %d, freq = %d\n",amount,arr[i][0],arr[i][1] );
			        #endif	
			    }
			    
			    if((k++) == 0){
                	printf("%d:%d",arr[i][0],currencyCount);	
                }
                else
                	printf(",%d:%d",arr[i][0],currencyCount);
                
			    
				break;	
			}

		}// for close
		
		int Exitcount=0;
		for(i=0; i < index;i++){
			if(arr[i][1] == 0)
				Exitcount++ ;
		}
		if(Exitcount == index)
			break;
	}// while close
	printf("\n");

}

int parseInput(char *denomination){
	int length = strlen(denomination);
	int i=0; 
	int num=0,num2=0;
	int countIF=0;
	int index=0;
	while(i < length){

		while(denomination[i] != ',' && i < length){
			
			#ifdef VERBOSE
				printf("denomination[i] = %c\n",denomination[i] );
			#endif	
			if((denomination[i] != ':') && countIF == 0)	
				num= num * 10 + denomination[i] - '0';
			else{
				if(countIF == 0){
					countIF = 1;
					i++;
				}
				num2 = num2 * 10 + denomination[i] - '0'; 
				
			}

			i++;
		}

		i++; // to avoid ,
		
		#ifdef VERBOSE
			printf("Num =%d and num2 = %d\n",num,num2);
		#endif


		arr[index][0]   = num;
		
		arr[index][1]   = num2;

		#ifdef VERBOSE
			printf("%d\n",arr[index][0] );
			printf("%d\n",arr[index][1] );
			//displayArr(index+2);
		#endif
		
		num=0;
		num2=0;
		countIF=0;
		index++;
	}//  while close


	//displayArr(index);
	return index;
}

void displayArr(int index){
	int i,j;
	
	for(i=0;i<index;i++){
		for(j=0;j<2;j++){
			printf("%d ",arr[i][j]);
		}
		printf("\n");
	}

}

