#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n) {
    int answer = 0;
    vector<int>dp(n+1,0);
    for(int i=1;i<=n;i++){
        dp[i] = dp[i-1] + i;
    }
    
    int left = 0;
    int right = 1;
    while(left<=right && right<=n){
        if(dp[right]-dp[left] <n){
            right++;
        }
        else if(dp[right]-dp[left]>n){
            left++;
        }
        else{
            left++;
            right++;
            answer++;
        }
    }

    return answer;
}