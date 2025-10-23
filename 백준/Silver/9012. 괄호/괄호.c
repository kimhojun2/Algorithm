#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

int main() {
	int N;
	scanf("%d", &N);
	
	char str[51];

	for (int i = 0;i < N;i++) {
		scanf("%s", str);
		int cnt = 0;
		int vps = 1;
		for (int j = 0;j < strlen(str);j++) {
			if (str[j] == '(') cnt++;
			else cnt--;

			if (cnt<0) {
				vps = 0;
				break;
			}
		}
		if (cnt != 0) vps = 0;

		printf("%s\n", vps ? "YES" : "NO");
	}


	return 0;
}