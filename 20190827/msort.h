#include <stdio.h>
#include <stdlib.h>

void display(int* arr, int len){
	int i = 0;
	for(i=0; i<len; i++)
		printf("[%d]", arr[i]);
	printf("\n");
}

void swap(int* a, int* b){
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
