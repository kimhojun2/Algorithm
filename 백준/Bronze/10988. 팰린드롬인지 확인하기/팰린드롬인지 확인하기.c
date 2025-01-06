#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define MAX_SIZE 101

char str[MAX_SIZE] = { 0, };

int main() {

    scanf("%100s", str);
    int l = strlen(str);

    int ans = 1;

    for (int i = 0;i < l;i++) {
        char front = str[i];
        char back = str[l - 1 - i];
        if (front != back) {
            ans = 0;
            break;
        }
    }

    printf("%d", ans);

    return 0;
}
