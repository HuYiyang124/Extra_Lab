#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 100000

void Swap(int *num, int i, int j)
{
     int temp;
     temp = num[i];
     num[i] = num[j];
     num[j] = temp;
}

void Heap(int *A, int size, int x){
    if (x < size){
        int root = x;
        int lchild = 2*x + 1; 
        int rchild = 2*x + 2; 
        if (lchild < size && A[root] < A[lchild]){
            root = lchild;
       }   
       if (rchild < size && A[root] < A[rchild]){
            root = rchild;
       } 
       if (root != x){
            Swap(A, root, x);
            Heap(A, size, root);
        }   
    }   
}

void CreateHeap(int *A, int size){
    int last = size - 1;
    int parent = (last - 1) / 2;
    for (int i = parent; i >= 0; i--){
        Heap(A, size, i);
    }   
}

void HeapSort(int *A, int size){
	CreateHeap(A, size);
	for(int i = size - 1; i >= 0; i--){
		Swap(A, i, 0);
		Heap(A, i, 0);
	}
}

void swap(int *a, int *b) {
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void Median3(int *A, int left, int right) {
	if (A[left] >= A[(left + right) / 2])
		swap(A + left, A + (right + left) / 2);
	if (A[left] >= A[right])
		swap(A + left, A + right);
	if (A[(left + right) / 2] >= A[right])
		swap(A + (right + left) / 2, A + right);
	swap(A + (right + left) / 2, A + right - 1);
}

int Partition(int *A, int left, int right) {
	Median3(A, left, right);
	int i = left + 1, j = right - 2, pivot = A[right - 1];
	while (1) {
		while (A[i] < pivot)
			i++;
		while (A[j] > pivot)
			j--;
		if (i < j) {
			swap(A + i, A + j);
			i++, j--;
		} else {
			break;
		}
	}
	swap(A + i, A + right - 1);
	return i;
}

void InsertionSort(int *A, int left, int right) {
	for (int p = left + 1; p <= right; p++) {
		int key = A[p];
		int i = p - 1;
		while (i >= 0 && A[i] > key) {
			A[i + 1] = A[i];
			i--;
		}
		A[i + 1] = key;
	}
}

void QuickSort(int *A, int left, int right) {
	if (left >= right)
		return;
	if (right - left <= 10) {
		InsertionSort(A, left, right);
		return;
	}
	int q = Partition(A, left, right);
	QuickSort(A, left, q - 1);
	QuickSort(A, q + 1, right);
}

int main(void) {

	int A1[SIZE];
    int A2[SIZE];

	for (int i = 0; i < SIZE; i++) {
		A1[i] = A2[i] = rand();
	}
	// for (int i = 0; i < SIZE; i++) {
	// 	printf("%d ",A1[i]);
	// }
	long start1 = clock();
	QuickSort(A1, 0, SIZE);
	long end1 = clock();
	double duration1 = (double) (end1 - start1) / CLOCKS_PER_SEC;
	printf("The time spent running QuickSort function is:%f\n", duration1);

	// for (int i = 0; i < SIZE; i++) {
	// 	printf("%d ",A1[i]);
	// }

    long start2 = clock();
	HeapSort(A2, SIZE);
	long end2 = clock();
	double duration2 = (double) (end2 - start2) / CLOCKS_PER_SEC;
	printf("The time spent running HeapSort function is:%f\n", duration2);

	return 0;
}
