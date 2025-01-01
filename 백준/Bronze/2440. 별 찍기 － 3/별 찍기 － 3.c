#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void) {

	int N = 0;
	scanf("%d", &N);

	for (int i = N;i > 0;i--) {
		for (int j = 1;j <= i;j++) {
			printf("*");
		}printf("\n");
	}
	return 0;
}