#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> vip(M);
    for (int i = 0; i < M; i++) {
        cin >> vip[i];
    }

    vector<int> dp(N + 1);
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= N; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    int result = 1;
    int prev = 0;
    for (int i = 0; i < M; i++) {
        int len = vip[i] - prev - 1;
        result *= dp[len];
        prev = vip[i];
    }
    result *= dp[N - prev];

    cout << result;
    return 0;
}
