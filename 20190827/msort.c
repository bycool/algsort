#include "msort.h"

void bubblesort(int* arr, int len){
	int i = 0, j = 0;

	for(i=0; i<len; i++){
		for(j=1;j<len;j++){
			if(arr[j-1]>arr[j]){
				swap(&arr[j-1], &arr[j]);
			}
		}
	}
}

void selectsort(int* arr, int len){
	int i = 0, j = 0;
	int min = 0;

	for(i=0; i<len; i++){
		min = i;
		for(j=i; j<len; j++){
			if(arr[j] < arr[min]){
				min = j;
			}
		}
		if(min != i){
			swap(&arr[min], &arr[i]);
		}
	}
}

void insertsort(int* arr, int len){
	int i = 0, j = 0;
	int tmp = 0;

	for(i=0; i<len; i++){
		tmp = arr[i];
		for(j=i; j>0 && arr[j-1]>=tmp; j--){
			arr[j] = arr[j-1];
		}
		arr[j] = tmp;
	}
}

void quicksort(int* arr, int b, int e){
	int bb = b, ee = e;
	int tmp = arr[b];

	if(b>=e) return ;

	while(bb < ee){
		while(arr[ee] >= tmp && bb < ee)
			ee--;

		while(arr[bb] <= tmp && bb < ee)
			bb++;

		if(bb<ee){
			swap(&arr[bb], &arr[ee]);
		}
	}

	arr[b] = arr[bb];
	arr[bb] = tmp;

	quicksort(arr, 0, bb-1);
	quicksort(arr, ee+1, e);

}

void mergesublist(int* arr, int* tmp, int b, int c, int e){
	int lb = b, le = c;
	int rb = c+1, re = e;
	int p = b, i = 0;

	while(lb <= le && rb <= re){
		if(arr[lb] <= arr[rb]){
			tmp[p++] = arr[lb++];
		}else{
			tmp[p++] = arr[rb++];
		}
	}

	while(lb <= le){
		tmp[p++] = arr[lb++];
	}

	while(rb <= re){
		tmp[p++] = arr[rb++];
	}

	for(i=0; i<p; i++){
		arr[i] = tmp[i];
	}
}
void mergesort(int* arr, int* tmp, int b, int e){
	if(b<e){
		int c = (b+e)/2;
		mergesort(arr, tmp, b, c);
		mergesort(arr, tmp, c+1, e);
		mergesublist(arr, tmp, b, c, e);
	}
}

void shellsort(int* arr, int len){
	int step = 1;
	int i = 0, j = 0;
	int tmp = 0;

	while(len/3 > step) step = step * 3 + 1;

	printf("org setp = %d\n", step);

	while(step>=1){
		for(i=step; i<len; i++){
			tmp = arr[i];
			for(j=i; j>=step && arr[j-step] >= tmp; j-=step){
				arr[j] = arr[j-step];
			}
			arr[j] = tmp;
		}
		step = step/3;
	}
}

void heapsub(int* arr, int i, int len){
	int child;

	for(i=i; 2*i+1<len; i=child){
		child = 2*i+1;
		if(child+1<len && arr[child+1]>=arr[child])
			child++;

		if(arr[i]<=arr[child])
			swap(&arr[i], &arr[child]);
	} 
}
void heapsort(int* arr, int len){
	int i = 0;

	for(i=len/2+1; i>=0; i--)
		heapsub(arr, i, len);

	for(i=len-1; i>=0; i--){
		swap(&arr[0], &arr[i]);
		heapsub(arr, 0, i);
	}
}

void main(){
	int arr[15] = {5,2,6,12,14,0,3,7,1,8,10,9,4,13,11};

//	bubblesort(arr, 15);
//	selectsort(arr, 15);
//	insertsort(arr, 15);
//	quicksort(arr, 0, 14);
#if 0
	int* tmp = (int*)malloc(sizeof(int)*15);
	mergesort(arr, tmp, 0, 14);
	free(tmp);
#endif
//	shellsort(arr, 15);
	heapsort(arr, 15);

	display(arr, 15);
}
