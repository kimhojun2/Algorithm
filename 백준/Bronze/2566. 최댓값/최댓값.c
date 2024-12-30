#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {

    int max = 0;
    int y, x = 0;

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            int t;
            scanf("%d", &t);
            if (max < t) {
                max = t;
                y = i;
                x = j;
            }
        }
    }
    printf("%d\n", max);
    printf("%d %d", y+1, x+1);

    return 0;
}