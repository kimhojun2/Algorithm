#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1001

int N = 0;
int arr[MAX_SIZE] = { 0, };


int compare(const void* A, const void* B) {
	int a = *(int*)A;
	int b = *(int*)B;
	
	if (a > b) {
		return 1;
	}
	if (a < b) {
		return -1;
	}

	return 0;
}

int main() {
	scanf("%d", &N);
	int* dp = (int*)calloc(N, sizeof(int) * N);

	for (int i = 0;i < N;i++) {
		scanf("%d", &arr[i]);
	}

	qsort(arr, N, sizeof(int), compare);
	
	
	dp[0] = arr[0];


	for (int i = 1;i < N;i++) {
		dp[i] = dp[i - 1] + arr[i];
	}

	int ans = 0;
	for (int i = 0;i < N;i++) {
		ans += dp[i];
	}

	printf("%d", ans);

	return 0;
}