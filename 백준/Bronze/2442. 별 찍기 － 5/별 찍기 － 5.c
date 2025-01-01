#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void) {

	int N = 0;
	scanf("%d", &N);

	for (int i = 0;i < N;i++) {
		for (int j = 0;j <N-1 -i;j++) {
			printf(" ");
		}
		for (int j = 0;j < (i * 2) + 1;j++) {
			printf("*");
		}

		printf("\n");
	}


	return 0;
}