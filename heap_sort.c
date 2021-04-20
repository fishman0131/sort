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

void max_headheap(int arr[], int dad, int len)
{
	int son = dad*2 + 1;
	
	if(arr[son] < arr[son+1] && len > son+1)
		++son;

	if(arr[dad] < arr[son])
		swap(&arr[dad],&arr[son]);

	return;
}

void heap_sort(int arr[], int len)
{
	if(len <= 1) return;

	for(int i= len/2 -1; i>=0; --i)
		max_headheap(arr, i, len);
	
	swap(&arr[len-1],&arr[0]);
	
	heap_sort(arr, len-1);
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
	
	heap_sort(arr, size);
	
	c_end   = clock();
	/******************************************/
	
	if(!is_right(arr,size)){
		printf("wrong sort\n");
		return 0;
	}
	
	printf("The heap sort used %.0f ms for sort %d numbers.\n",difftime(c_end,c_start), size);
	
	/*for(int i=0; i<size; ++i)
		printf("%d ",arr[i]);
	printf("\n");*/
	
	return 0;
}