#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int arr[1000000] = { 0, };

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


int main() {
	int N = 0;
	scanf("%d", &N);

	for (int i = 0;i < N;i++) {
		scanf("%d", &arr[i]);
	}

	qsort(arr, N, sizeof(int), compare);

	for (int i = 0;i < N;i++) {
		printf("%d\n", arr[i]);
	}


	return 0;
}