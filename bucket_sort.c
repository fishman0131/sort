#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <math.h>
#include <time.h>
#include <stdbool.h>

void bucket_sort(int arr[], int len, int bucket_num)
{
	int bucket[bucket_num][bucket_num];
	int i, j, k, m = 0; 
	
	for(i = 0; i < bucket_num; ++i)
		for(j = 0; j < bucket_num; ++j)
			bucket[i][j]=0;
	
	for(i = 0; i < len; ++i)
		bucket[(arr[i])/bucket_num][(arr[i])%bucket_num]++;
		
		
	for(i = 0; i < bucket_num; ++i){
		for(j = 0; j < bucket_num; ++j){
			if(bucket[i][j]){
				for(k = 0; k < bucket[i][j]; ++k)
					arr[m++]=i*bucket_num+j;
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
	
	bucket_sort(arr, size, 100);
	
	c_end   = clock();
	/******************************************/
	
	if(!is_right(arr,size)){
		printf("wrong sort\n");
		return 0;
	}
	
	printf("The bucket sort used %.0f ms for sort %d numbers.\n",difftime(c_end,c_start), size);
	
	/*for(int i=0; i<size; ++i)
		printf("%d ",arr[i]);
	printf("\n");*/
	
	return 0;
}