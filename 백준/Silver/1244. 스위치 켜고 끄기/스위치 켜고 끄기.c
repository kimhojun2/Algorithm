#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int sw[101];

int main(void) {
    int N;
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) scanf("%d", &sw[i]);

    int M;
    scanf("%d", &M);
    while (M--) {
        int gender, pos;
        scanf("%d %d", &gender, &pos);

        if (gender == 1) {
            for (int j = pos; j <= N; j += pos)
                sw[j] = !sw[j];
        }
        else {
            sw[pos] = !sw[pos];
            int l = pos - 1, r = pos + 1;
            while (l >= 1 && r <= N && sw[l] == sw[r]) {
                sw[l] = !sw[l];
                sw[r] = !sw[r];
                l--; r++;
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        printf("%d ", sw[i]);
        if (i % 20 == 0) {
            printf("\n");
        }
    }
    return 0;
}
