#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <math.h>
#include <time.h>
#include <stdbool.h>

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void shell_sort(int arr[], int len)
{
	int i, j, k;
	
	for(i = len/2;  i > 0; i = i/2){
		for(j = i; j < len; ++j){
			k = j;
			while(k - i >= 0 && arr[k] < arr[k-i]){
				swap(&arr[k], &arr[k-i]);
				
				k -= i;
			}
		}
	}
}

bool is_right(int arr[], int len)
{
	for(int i = 1; i < len; ++i){
		if(arr[i-1] > arr[i]){
			return false;
		}
	}
	return true;
}

int main(int argc , char** argv)
{
	if(argc < 2 || argv[1]==NULL)
	{
		printf("wrong input\n");
		return -1;
	}
	
	int size = atoi(argv[1]);
	int arr[size];
	
	time_t c_start, c_end;
	
	for(int i=0; i<size; ++i)
	{
		arr[i]=rand()%10000;
		//printf("%d ",arr[i]);
	}	
	//printf("\n");
	
	/******************************************/
	c_start = clock();
	
	shell_sort(arr, size);
	
	c_end   = clock();
	/******************************************/
	
	if(!is_right(arr,size)){
		printf("wrong sort\n");
		return 0;
	}
	
	printf("The shell sort used %.0f ms for sort %d numbers.\n",difftime(c_end,c_start), size);
	
	//for(int i=0; i<size; ++i)
	//	printf("%d ",arr[i]);
	//printf("\n");
	
	return 0;
}