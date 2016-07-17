#include <stdio.h>
#include <string.h>
int arr[100];

int getData(char *denomination){
	int index=0, num=0,i=0;
	// input read module
	int length = strlen(denomination);
	while(i < length){
		while(denomination[i] != ',' && i < length){
			
			#ifdef VERBOSE
				printf("denomination[i] = %c\n",denomination[i] );
			#endif	
			num= num * 10 + denomination[i] - '0';
			i++;
		}
		i++;
		
		#ifdef VERBOSE
			printf("Num =%d\n",num);
		#endif
		arr[index++] = num;
		num=0;
	}//  while close
	return index;
}

void __optimal_change_maker(char *denomination, int amount){
	
		int i=0;
		//index=0;
		int num=0;
		
		int length = strlen(denomination);
		printf("%s\n",denomination );
		#ifdef DEBUG
			printf("denomination = %s\n",denomination );
		#endif

		 
		int index = getData(denomination);
		 
		
		// first sort array
		//index = sort(index);
		// sort ends here

		
		int temp=0,count=0;	
		int val=0, val1=0;
		int finalVal=0;
		int finalIndex=0;
		val  = calCurrency(amount, index,0,0);
		val1 = calCurrency(amount, index,1,0);
		#ifdef DEBUG
			printf("\nFirst Val1=%d Val2=%d Index=%d\n",val,val1,index);
		#endif
		
		while(1 && i < index){
			
			if(val <= val1){
				if(count++ == 0){
				finalVal = val;
				finalIndex = i;
				}
				#ifdef DEBUG
					printf("\nIF Val1=%d Val2=%d, finalIndex=%d , finalVal=%d\n",val,val1,finalIndex,finalVal);
				#endif
				if(++i < index) {
					val  = calCurrency(amount, index,i,0);
					if(val >= finalVal)
						val = finalVal;
					else{
						finalVal = val;
						finalIndex = i-1;
					}
				}
				else 
					break;
				
				if(++i < index) {
					#ifdef DEBUG
						printf("\nCloser Val1=%d Val2=%d, finalIndex=%d , finalVal=%d\n",val,val1,finalIndex,finalVal);
				    #endif	
					val1  = calCurrency(amount, index,i,0);
					if(val1 >= finalVal)
						val1 = finalVal;
					else{
						finalVal = val1;
						finalIndex = i-1;
					}
					#ifdef DEBUG
						printf("\nCloser Val1=%d Val2=%d, finalIndex=%d , finalVal=%d\n",val,val1,finalIndex,finalVal);
				    #endif	
				}
				else 
					break;
				val1 = calCurrency(amount, index,++i,0);
			}
			else{
				if(count++ == 0){
				finalVal = val1;
				finalIndex = i-1;
				}
				#ifdef DEBUG
					printf("\nElse Val1=%d Val2=%d, finalIndex=%d , finalVal=%d\n",val,val1,finalIndex,finalVal);
				#endif
				if(++i < index){
					val  = calCurrency(amount, index,i,0);
					if(val >= finalVal)
						val = finalVal;
					else{
						finalVal = val;
						finalIndex = i-1;
					}
				}
				else 
					break;
				
				if(++i < index) {
					val1  = calCurrency(amount, index,i,0);
					if(val1 >= finalVal)
						val1 = finalVal;
					else{
						finalVal = val1;
						finalIndex = i-1;
					}
				}
				else 
					break;
				 

			}
		}
		
		calCurrency(amount, index,finalIndex,1);
		printf("\n");
		//printf("CurrencyCount = %d\n",finalIndex);
	}

int calCurrency(int amount, int index, int begin,int print){
	int currencyCount=0;
	int arr_length = index;
	int i=begin,k=0,count=0;
	//int c=5;
	while(amount != 0 ){
			//printf("Arr = %d \n",arr[i]);
			for(i=begin; i< arr_length; i++){
				if(amount >= arr[i]){
					#ifdef DEBUG
				    	printf("First Amount = %d, Note = %d CurrencyCount =%d\n",amount, arr[i],currencyCount);
				    #endif
					count = amount / arr[i];
					amount = amount % arr[i];
					currencyCount += count;
					if(print){
		                if((k++) == 0){
		                	printf("%d:%d",arr[i],count);	
		                }
		                else
		                	printf(",%d:%d",arr[i],count);
	                }
				    #ifdef DEBUG
				    	printf("Else Amount = %d Note = %d, CurrencyCount =%d\n",amount,arr[i],currencyCount);
				    #endif

					break;	
				   }

				}// for loop ends
		
	}//  while loop ends
	//printf("\n");
	return currencyCount;

}

int sort(int index){
	int i=0;
	int j=0;
	int key,k;
	int arr_length= index;
	for(i=1;i<index; i++){
		j=i-1;
		key = arr[i];
		while(j >=0 && key < arr[j]){
			arr[j+1] = arr[j];
			j=j-1;
		}

		arr[j+1] = key;
	}
}