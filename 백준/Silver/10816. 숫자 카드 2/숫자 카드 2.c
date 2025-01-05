#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define OFFSET 10000000
#define SIZE 20000001

int N = 0, M=0;
int arr[SIZE] = { 0, };

int main() {

    scanf("%d", &N);
    
    for(int i=0;i<N;i++){
        int now = 0;
        scanf("%d", &now);
        arr[now + OFFSET] += 1;

    }
    scanf("%d", &M);

    for (int i = 0;i < M;i++) {
        int check = 0;
        scanf("%d", &check);
        printf("%d ", arr[check+OFFSET]);
    }
    return 0;
}
