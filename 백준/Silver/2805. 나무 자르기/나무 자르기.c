#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int main() {
	int N, i, max = 0;
	long long M, mid,cnt = 0;
	scanf("%d %lld", &N, &M);
	int* arr = (int*)malloc(sizeof(int) * N);
	for (i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
		if (arr[i] > max)
			max = arr[i];
	}

	long long left, right, ans = 0;
	left = 0;
	right = max;

	while (left <= right) {
		mid = (left + right) / 2;
		cnt = 0;
		for (i = 0; i < N; i++)
			if (arr[i] > mid) {
				cnt += (arr[i] - mid);
			}

		if (cnt >= M) {
			if (ans < mid)
				ans = mid;
			left = mid + 1;
		}
		else
			right = mid - 1;
	}
	printf("%lld", ans);
	free(arr);
	return 0;
}