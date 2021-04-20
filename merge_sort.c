#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <math.h>
#include <time.h>
#include <stdbool.h>

void merge_sort(int arr[], int reg[], int start, int end)
{
	if(start >= end) return;
	int len= end - start, mid= len/2 + start;
	int start1 = start, end1 = mid;
    int start2 = mid + 1, end2 = end;

	merge_sort(arr, reg, start1, end1);
    merge_sort(arr, reg, start2, end2);
	
    int k = start;
    while (start1 <= end1 && start2 <= end2)
        reg[k++] = arr[start1] < arr[start2] ? arr[start1++] : arr[start2++];
    while (start1 <= end1)
        reg[k++] = arr[start1++];
    while (start2 <= end2)
        reg[k++] = arr[start2++];
    for (k = start; k <= end; k++)
        arr[k] = reg[k];
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
	int arr[size],reg[size];
	
	time_t c_start, c_end;
	
	for(int i=0; i<size; ++i)
	{
		arr[i]=rand()%10000;
		//printf("%d ",arr[i]);
	}	
	//printf("\n");
	
	/******************************************/
	c_start = clock();
	
	merge_sort(arr, reg, 0, size-1);
	
	c_end   = clock();
	/******************************************/
	
	if(!is_right(arr,size)){
		printf("wrong sort\n");
		return 0;
	}
	
	printf("The merge sort used %.0f ms for sort %d numbers.\n",difftime(c_end,c_start), size);
	
	/*for(int i=0; i<size; ++i)
		printf("%d ",arr[i]);
	printf("\n");*/
	
	return 0;
}