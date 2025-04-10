#include <string>
#include <vector>
#include <iostream>
using namespace std;


int solution(int n, vector<int> coins) {
    vector<int> dp(n + 1);
    dp[0] = 1;

    for (int coin : coins)
    {
        for (int i = coin; i <= n; ++i)
        {
            dp[i] += dp[i - coin];
            dp[i] %= 1000000007;
        }
    }
    
    return dp[n];
}
