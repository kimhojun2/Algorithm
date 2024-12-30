#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#define MAX_SIZE 100

int main() {

    int arr[MAX_SIZE][MAX_SIZE] = {0};
    int N = 0;
    int x, y;
    int cnt = 0;

    scanf("%d", &N);

    for (int i = 0;i < N;i++) {
        scanf("%d %d", &x, &y);
        for (int j = 0;j < 10;j++) {
            for (int k = 0;k < 10;k++) {
                arr[x + j][y + k] = 1;
            }
        }
    }

    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            if (arr[i][j] == 1)
                cnt++;
        }
    }
    printf("%d", cnt);

    return 0;
}