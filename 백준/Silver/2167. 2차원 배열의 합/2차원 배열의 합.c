#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int arr[301][301] = { 0, };
int dp[301][301] = { 0, };
int N, M, K;

int main() {
    scanf("%d %d", &N, &M);

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            dp[i][j] = arr[i][j];
            if (i > 1) dp[i][j] += dp[i - 1][j];
            if (j > 1) dp[i][j] += dp[i][j - 1];
            if (i > 1 && j > 1) dp[i][j] -= dp[i - 1][j - 1];
        }
    }

    scanf("%d", &K);

    for (int tc = 0; tc < K; tc++) {
        int i, j, x, y, ans = 0;
        scanf("%d %d %d %d", &i, &j, &x, &y);

        ans = dp[x][y];
        if (i > 1) ans -= dp[i - 1][y];
        if (j > 1) ans -= dp[x][j - 1];
        if (i > 1 && j > 1) ans += dp[i - 1][j - 1];

        printf("%d\n", ans);
    }

    return 0;
}
