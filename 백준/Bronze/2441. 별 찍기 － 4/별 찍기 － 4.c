#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void) {

	int N = 0;
	scanf("%d", &N);

	for (int i = 0;i < N;i++) {
		for (int j = 0;j < i;j++) {
			printf(" ");
		}
		for (int k = 1;k <= N - i;k++) {
			printf("*");
		}

		printf("\n");
	}


	return 0;
}