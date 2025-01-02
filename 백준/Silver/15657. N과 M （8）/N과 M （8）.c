#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int N = 0, M = 0;
int arr[9] = { 0, };
int ans[9] = { 0, };

void back(int level, int max);

int compare(const void* a, const void* b) {
	int num1 = *(int*)a;
	int num2 = *(int*)b;

	if (num1 < num2) {
		return -1;
	}
	else if (num1 > num2) {
		return 1;
	}

	return 0;
}


int main() {

	int i = 0;
	scanf("%d %d", &N, &M);
	while (i < N) {
		scanf("%d", &arr[i]);
		i++;
	}
	qsort(arr, N, sizeof(int), compare);

	back(0, 0);

	return 0;
}

void back(int level, int max) {
	if (level == M) {
		for (int i = 0;i < level;i++) {
			printf("%d ", ans[i]);
		}
		printf("\n");
	}
	else {
		for (int i = 0;i < N;i++) {
			if (arr[i] >= max) {
				ans[level] = arr[i];
				back(level + 1,arr[i]);
			}
		}
	}
}