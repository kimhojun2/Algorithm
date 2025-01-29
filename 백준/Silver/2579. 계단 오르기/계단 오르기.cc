#include <iostream>
#include <algorithm>
using namespace std;

int arr[301] = { 0, };
int dp[301][2] = { 0, };

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    dp[1][0] = arr[1];
    dp[1][1] = arr[1];

    if (N > 1) {
        dp[2][0] = arr[2];
        dp[2][1] = arr[1] + arr[2];
    }
    for (int i = 3;i <= N;i++) {
        // 1칸 올라간다고 계산할 때
        dp[i][1] = dp[i - 1][0] + arr[i];
        // 2칸 올라간다고 계산할 때
        dp[i][0] = max(dp[i - 2][0], dp[i - 2][1]) + arr[i];

    }

    // Test: dp 배열 출력
    /*for (int i = 1; i <= N; i++) {
        cout << "dp[" << i << "][0]: " << dp[i][0]
            << ", dp[" << i << "][1]: " << dp[i][1] << '\n';
    }*/
    cout << max(dp[N][0], dp[N][1]);

    return 0;
}
