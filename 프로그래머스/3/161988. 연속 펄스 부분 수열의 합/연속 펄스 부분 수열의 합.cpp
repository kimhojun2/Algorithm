#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long solution(vector<int> sequence) {
    int n = sequence.size();
    vector<vector<long long>> dp(n, vector<long long>(2));
    dp[0][0] = 1LL * sequence[0];
    dp[0][1] = -1LL * sequence[0];

    for (int i = 1; i < n; i++) {
        dp[i][0] = max(1LL * sequence[i], dp[i - 1][1] + 1LL * sequence[i]);
        dp[i][1] = max(-1LL * sequence[i], dp[i - 1][0] - 1LL * sequence[i]);
    }

    long long answer = -100000;
    for (int i = 0; i < n; i++) {
        answer = max({answer, dp[i][0], dp[i][1]});
    }

    return answer;
}
