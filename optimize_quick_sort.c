#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>

void swap(int *a, int *b){			
		int temp = *a ;	
		*a = *b ;	
		*b = temp ;	
}

void insert_sort(int arr[], int start, int end)
{
	int i, j;
	for(int i = (start + 1); i < end + 1; ++i){
		j = i;
		while(j-1 >= 0 && arr[j] < arr[j-1]){
			swap(&arr[j], &arr[j-1]);
			--j;
		}
	}
}

void quick_sort(int arr[], int start, int end)
{
	if(start >= end) return;
	
	if(end - start <= 10){
		insert_sort(arr, start, end);
		return;
	}

	int i = start, j = end-1;
	
	if(end - start >= 2){
		int mid = (start + end)/2;
		if((arr[mid]-arr[start]) * (arr[start]-arr[end]) >= 0)
			swap(&arr[start],&arr[end]);
		else if((arr[start]-arr[mid]) * (arr[mid]-arr[end]) >= 0)
			swap(&arr[mid],&arr[end]);
	}
	
	while(i < j)
	{
		while(i < j && arr[i] <= arr[end]){
			++i;
		}
		
		while(i < j && arr[j] >= arr[end]){
			--j;
		}
		
		swap(&arr[i], &arr[j]);
	}
	if(arr[i] > arr[end])
		swap(&arr[i],&arr[end]);
	
	quick_sort(arr, start, i);
	quick_sort(arr, i+1, end);
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
	
	quick_sort(arr, 0, size-1);
	
	c_end   = clock();
	/******************************************/
	
	if(!is_right(arr,size)){
		printf("wrong sort\n");
		return 0;
	}
	
	printf("The quick sort O2 used %.0f ms for sorting %d numbers.\n",difftime(c_end,c_start), size);
	
	//for(int i=0; i<size; ++i)
		//printf("%d ",arr[i]);
	//printf("\n");
	
	return 0;
}