#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    int dp[100][100] = {0};
    vector<vector<bool>> isPuddle(n, vector<bool>(m, false));

    for (auto puddle : puddles) {
        isPuddle[puddle[1] - 1][puddle[0] - 1] = true;
    }

    if (isPuddle[0][0]) return 0;
    dp[0][0] = 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (isPuddle[i][j]) {
                dp[i][j] = 0;
                continue;
            }
            if (i > 0) dp[i][j] = (dp[i][j] + dp[i-1][j]) % 1000000007;
            if (j > 0) dp[i][j] = (dp[i][j] + dp[i][j-1]) % 1000000007;
        }
    }
    
    answer = dp[n-1][m-1];
    return answer;
}
