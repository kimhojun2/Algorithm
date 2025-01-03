#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int dp[100001] = { 0, };
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

    

    for(int i =0;i<M;i++){
        int ans = 0;
        int x = 0, y = 0;
        scanf("%d %d", &x, &y);
        
        ans = dp[y] - dp[x-1];

        printf("%d\n", ans);
    }
    

    return 0;
}
