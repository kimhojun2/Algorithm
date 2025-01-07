#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int stick = 64;


int main() {
	int X = 0;
	scanf("%d", &X);
	int cnt = 0;
	int sum = 0;
	
	while (sum!=X) {

		if(sum+stick<=X){
			sum += stick;
			cnt += 1;
			if (sum == X) {
				break;
			}
		}
		stick /= 2;
		
	}
	printf("%d", cnt);

	return 0;
}