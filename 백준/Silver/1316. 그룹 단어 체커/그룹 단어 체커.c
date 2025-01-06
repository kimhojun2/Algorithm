#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define ALPHABET_SIZE 26	
#define MAX_SIZE 101


int N = 0;

int main() {

	scanf("%d", &N);

	int ans = N;

	for (int i = 0;i < N;i++) {
		char str[MAX_SIZE] = { 0 };
		int checklist[ALPHABET_SIZE] = { 0, };
		char before = '\0';

		scanf("%100s", str);
		for (int j = 0;str[j] != '\0';j++) {
			char now = str[j];
			int now_idx = now - 'a';

			if (before == now) {
				continue;
			}
			else {
				if (checklist[now_idx] != 0) {
					ans --;
					break;
				}
				else {
					checklist[now_idx] += 1;
					before = now;
				}
				
			}
		}
	}

	printf("%d", ans);


	return 0;
}