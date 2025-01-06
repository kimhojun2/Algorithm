#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define MAX_SIZE 1000001

char str[MAX_SIZE] = { 0 };
int check[26] = { 0 };

int main() {
    scanf("%s", str);

    int len = strlen(str);
    int MAX = 0;
    char MAX_S = '?';

    for (int i = 0; i < len; i++) {
        char now = str[i];

        if (now >= 'a' && now <= 'z') {
            now -= 32;
        }

        int index = now - 'A';

        if (index >= 0 && index < 26) {
            check[index]++;

            if (check[index] > MAX) {
                MAX = check[index];
                MAX_S = now;
            }
            else if (check[index] == MAX) {
                MAX_S = '?';
            }
        }
    }

    printf("%c\n", MAX_S);

    return 0;
}
