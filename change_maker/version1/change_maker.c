#include <stdio.h>
#include <string.h>
void change_maker(char *denomination, int amount){
	int length = strlen(denomination);
	int i=0, index=0;
	int num=0;
	int arr[100];

	#ifdef DEBUG
		printf("denomination = %s\n",denomination );
	#endif
	// input read module
	while(i < length){
		while(denomination[i] != ',' && i < length){
			
			#ifdef VERBOSE
				printf("denomination[i] = %c\n",denomination[i] );
			#endif	
			num= num * 10 + denomination[i] - '0';
			i++;
		}
		i++;
		
		#ifdef DEBUG
			printf("Num =%d\n",num);
		#endif
		arr[index++] = num;
		num=0;
	}//  while close
	
	// calculation module
	// first sort array
	i=0;
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
	// sort ends here
	char *result, *result1, *result2;
	int count=0;
	k=0;
	while(amount != 0){
		for(i=0; i< arr_length; i++){
			if(amount <= arr[i]){
				count = amount / arr[i-1];
				amount = amount % arr[i-1];
				//char value1[10];
				//char value2[10];
				//char del[2]=":";
				//snprintf(value1, 10, "%d", arr[i-1]);
				//snprintf(value2, 10, "%d", count);
                if((k++) == 0){
                	printf("%d:%d",arr[i-1],count);	
                }
                else
                	printf(",%d:%d",arr[i-1],count);
                
			    
				break;	
			   }

			}// for loop ends
			if(i == arr_length){
				count = amount / arr[i-1];
				amount = amount % arr[i-1];
				if(k++ == 0){
                	printf("%d:%d",arr[i-1],count);	
                }
                else
                	printf(",%d:%d",arr[i-1],count);
                
			    
				
			}
		}//  while loop ends
		printf("\n");
	}

