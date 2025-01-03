#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int dp[10001] = { 0, };
int N = 0, M = 0;


int main() {

    scanf("%d %d", &N, &M);
    for (int i = 1;i <= N;i++) {
        int now = 0;
        scanf("%d", &now);
        if (i == 1) {
            dp[i] = now;
        }
        else {
            dp[i] = dp[i - 1] + now;
        }
    }
    int left = 0;
    int right = 0;
    int ans = 0;
    while (right <= N && left <= right) {
        int total = dp[right] - dp[left];
        if (total == M) {
            ans += 1;
            left++;
            right++;
        }
        else if (total < M) {
            right++;
        }
        else {
            left++;
        }

    }
    
    printf("%d", ans);

    return 0;
}
