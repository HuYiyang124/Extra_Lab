#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define SIZE 100000
void HeapSort(int *A, int size);
bool Insert(int *A, int size, int x);
int DeleteMax(int *A, int size);
void QuickSort(int *A, int left, int right);
int Partition(int *A, int left, int right);
void InsertionSort(int *A, int left, int right);
void Median3(int *A, int left, int right);

void QuickSort(int *A, int left, int right) {
	if (right - left <= 5) {
		InsertionSort(A, left, right);
		return;
	}
	int q = Partition(A, left, right);
	QuickSort(A, left, q - 1);
	QuickSort(A, q + 1, right);

}
int Partition(int *A, int left, int right) {
	Median3(A, left, right);
	int i = left + 1, j = right - 2, pivot = A[right - 1];
	while (1) {
		while (i < j && A[i] < pivot)
			i++;
		while (i < j && A[j] > pivot)
			j--;
		if (i < j) {
			int temp = A[j];
			A[j] = A[i];
			A[i] = temp;
			i++;
			j--;
		} else
			break;
	}
	int temp = A[i];
	A[i] = A[right - 1];
	A[right - 1] = temp;
	return i;
}

void Median3(int *A, int left, int right) {
	int median = (right + left + 1) / 2;
	if (A[left] > A[right]) {
		int temp = A[right];
		A[right] = A[left];
		A[left] = temp;
	} else {
		if (A[median] < A[left]) {
			int temp = A[left];
			A[left] = A[median];
			A[median] = temp;
		} else if (A[median] > A[right]) {
			int temp = A[right];
			A[right] = A[median];
			A[median] = temp;
		} else {

		}
	}
	int temp2 = A[median];
	A[median] = A[right - 1];
	A[right - 1] = temp2;
}

void InsertionSort(int *A, int left, int right) {
	for (int p = left + 1; p <= right; p++) {
		int key = A[p];
		int i = p - 1;
		while (i >= left && A[i] > key) {
			A[i + 1] = A[i];
			i--;
		}
		A[i + 1] = key;
	}
}


int maxSize = 100000;

bool Insert(int *A, int n, int x) {
	if (n >= maxSize)
		return false;
	int hole = n;
	while (hole > 0 && x > A[(hole - 1) / 2]) {
		A[hole] = A[(hole - 1) / 2];
		hole = (hole - 1) / 2;
	}
	A[hole] = x;
	return true;
}

int DeleteMax(int *A, int size) {
	if (size <= 0)
		return false;
	int max = A[0], hole = 0, x = A[--size], sid;
	while (2 * hole + 1 <= size - 1) {
		if (2 * hole + 2 <= size - 1) {
			if (A[2 * hole + 1] <= A[2 * hole + 2])
				sid = 2 * hole + 2;
			else
				sid = 2 * hole + 1;
		}
		else
			sid = 2 * hole + 1;
		if (x >= A[sid]) {
			break;
		} else {
			A[hole] = A[sid];
			hole = sid;
		}
	}
	A[hole] = x;

	return max;
}

void HeapSort(int *A, int size) {
	for (int i = 0; i <= size - 1; i++) {
		Insert(A, i, A[i]);
	}

	for (int i = size - 1; i >= 0; i--) {
		A[i] = DeleteMax(A, i + 1);
	}
}

int main(void) {
	int A1[SIZE], A2[SIZE];

	srand(time(NULL));
	for(int i = 0; i < SIZE; i++) {
		A2[i] = A1[i] = rand();
	}

	clock_t start = clock();
	QuickSort(A1, 0, SIZE-1);
	clock_t end = clock();
	printf("Quick Sort: %f ms\n", 1000.0 * (double)(end - start) / CLOCKS_PER_SEC);
	
	// for (int i = 0; i < SIZE; i++) {
	// 	printf("%d ",A1[i]);
	// }
	start = clock();
	HeapSort(A2, SIZE);
	end = clock();
	printf("Heap Sort: %f ms\n", 1000.0 * (double)(end - start) / CLOCKS_PER_SEC);
	return 0;
}
