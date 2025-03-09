#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int> > land)
{
    int answer = 0;
    int N = land.size();
    vector<vector<int>>dp(N, vector<int>(4,0));
    dp[0] = land[0];
    for(int i=1;i<N;i++){
        for(int j=0;j<4;j++){
            int max_ = 0;
            for (int k = 0; k < 4; k++) {
                if (k != j) {
                    max_ = max(max_, dp[i - 1][k]);
                }
            }
            dp[i][j] = land[i][j] + max_;
        }
    }
     answer = *max_element(dp[N - 1].begin(), dp[N - 1].end());
    return answer;
}