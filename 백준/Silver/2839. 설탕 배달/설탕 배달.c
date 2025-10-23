#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {
	int N;
	scanf("%d", &N);
	
	int ans = 0;

	while (N) {
		if (N % 5 == 0) {
			ans += (N / 5);
			break;
		}
		if (N - 3 < 0) {
			ans = -1;
			break;
		}
		N -= 3;
		ans++;
	}

	printf("%d", ans);


	return 0;
}