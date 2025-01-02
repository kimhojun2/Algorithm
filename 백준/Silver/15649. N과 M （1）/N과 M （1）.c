#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int N = 0, M = 0;
int arr[9] = { 0, };
int visited[9] = { 0, };

void back(int level);



int main() {

	scanf("%d %d", &N, &M);
	back(0);

	return 0;
}


void back(int level) {
	if (level == M) {
		for (int i = 0;i < M;i++) {
			printf("%d ", arr[i]);
		}
		printf("\n");
	}
	else {
		for (int i = 1;i <= N;i++) {
			if (visited[i] == 0) {
				arr[level] = i;
				visited[i] = 1;
				back(level + 1);
				visited[i] = 0;
			}
		}
	}
}