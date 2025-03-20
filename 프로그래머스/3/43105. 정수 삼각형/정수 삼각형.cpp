#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    vector<vector<int>>dp(triangle.size());
    dp[0].push_back(triangle[0][0]);
    for(int i=1;i<triangle.size();i++){
        for(int j=0;j<triangle[i].size();j++){
            if(j == 0) dp[i].push_back(dp[i-1][0] + triangle[i][0]);
            else if(j==triangle[i].size()-1) dp[i].push_back(dp[i-1][j-1] + triangle[i][j]);
            else{
                int before = max(dp[i-1][j], dp[i-1][j-1]);
                dp[i].push_back(before+triangle[i][j]);
            }
        }
    }
    for(int i : dp[triangle.size()-1]){
        answer = max(answer, i);
    }
    return answer;
}