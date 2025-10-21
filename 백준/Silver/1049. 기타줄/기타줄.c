#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

int main(void) {
    int N, M;
    scanf("%d %d", &N, &M);

    int min_set = 1000, min_each = 1000; 

    for (int i = 0; i < M; i++) {
        int set_price, each_price;
        scanf("%d %d", &set_price, &each_price);

        if (set_price < min_set) min_set = set_price;
        if (each_price < min_each) min_each = each_price;
    }

    int cost = 0;

    if (min_set >= min_each * 6) {
        cost = N * min_each;
    }
    else {
        cost = (N / 6) * min_set + (N % 6) * min_each;

        if ((N % 6) * min_each > min_set)
            cost = ((N / 6) + 1) * min_set;
    }

    printf("%d", cost);
    return 0;
}
