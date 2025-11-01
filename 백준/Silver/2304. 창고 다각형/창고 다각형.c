#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);

    int H[1001] = {0};
    int x, h;
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &x, &h);
        H[x] = h;
    }

    int peakX = 0, peakH = 0;
    for (int i = 0; i <= 1000; i++) {
        if (H[i] > peakH) { peakH = H[i]; peakX = i; }
    }

    int area = 0, cur = 0;
    for (int i = 0; i <= peakX; i++) {
        if (H[i] > cur) cur = H[i];
        area += cur;
    }

    cur = 0;
    for (int i = 1000; i > peakX; i--) {
        if (H[i] > cur) cur = H[i];
        area += cur;
    }

    printf("%d", area);
    return 0;
}
