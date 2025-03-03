#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N, K;
    cin >> N >> K;
    vector<int> dp(K + 1, 0);

    for (int i = 0; i < N; i++) {
        int W, V;
        cin >> W >> V;

        if (W > K) continue;

        for (int i = K; i >= W; i--) {
            dp[i] = max(dp[i], dp[i - W] + V);
        }
    }

    cout << dp[K];
    return 0;
}
