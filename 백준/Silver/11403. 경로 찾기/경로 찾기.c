#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 101

int N = 0;
int arr[MAX_SIZE][MAX_SIZE] = { 0, };



int main() {
	scanf("%d", &N);
	
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			scanf("%d", &arr[i][j]);
		}
	}


	for (int k = 0; k < N; k++) {         // 중간 정점
		for (int i = 0; i < N; i++) {     // 시작 정점
			for (int j = 0; j < N; j++) { // 도착 정점
				if (arr[i][k] && arr[k][j]) {
					arr[i][j] = 1;
				}
			}
		}
	}



	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			printf("%d ", arr[i][j]);
		}printf("\n");
	}


	return 0;
}