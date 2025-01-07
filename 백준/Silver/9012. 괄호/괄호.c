#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 51

int N = 0;
char arr[MAX_SIZE] = { 0, };


int vps(char* arr) {
	int pair = 0;
	for (int i = 0;arr[i] != '\0';i++) {
		if (arr[i] == '(') {
			pair += 1;
		}
		else if (arr[i] == ')') {
			pair -= 1;
			if (pair < 0) {
				return 0;
			}
		}
	}
	
	return pair == 0 ? 1 : 0;
	
}


int main() {
	scanf("%d", &N);
	int ans = 0;
	for (int tc = 0;tc < N;tc++) {
		scanf("%s", arr);
		
		if (vps(&arr) == 1) {
			printf("YES");
		}
		else {
			printf("NO");
		}
		printf("\n");
	}

	return 0;
}