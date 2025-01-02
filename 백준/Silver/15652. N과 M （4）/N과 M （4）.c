#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int N = 0, M = 0;
int arr[8] = { 0, };

void back(int level, int max);

int main() {

	scanf("%d %d", &N, &M);
	back(0,0);

	return 0;
}

void back(int level,int max) {
	if (level == M) {
		for (int i = 0;i < level;i++) {
			printf("%d ", arr[i]);
		}
		printf("\n");
	}
	else {
		for (int i = 1;i <= N;i++) {
			if (i >= max) {
				arr[level] = i;
				back(level + 1,i);
			}
		}
	}
}