#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 500000

int arr[MAX_SIZE] = { 0, };

int compare(const void* A, const void* B) {
	int a = *(int*)A;
	int b = *(int*)B;

	if (a > b) {
		return 1;
	}

	else if (a < b) {
		return -1;
	}
	else {
		return 0;
	}
}

int binary_search(int N, int target) {
	int left = 0;
	int right = N-1;
	
	while (left <= right) {
		int mid = (left + right) / 2;
		
		if (arr[mid] > target) {
			right = mid - 1;
		}
		else if (arr[mid] < target) {
			left = mid + 1;
		}
		else {
			return 1;
		}

	}

	return 0;
}



int main() {

	int N = 0;
	scanf("%d", &N);

	for (int i = 0;i < N;i++) {
		scanf("%d", &arr[i]);
	}

	qsort(arr, N, sizeof(int), compare);

	int M = 0;
	scanf("%d", &M);
	for (int i = 0;i < M;i++) {
		int target = 0;
		scanf("%d", &target);
		printf("%d ", binary_search(N, target));
	}


	return 0;
}