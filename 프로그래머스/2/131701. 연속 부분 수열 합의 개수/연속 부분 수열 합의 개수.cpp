#include <string>
#include <vector>
#include <iostream>
// #include <map>

using namespace std;

int solution(vector<int> elements) {
    int answer = 0;
    int N = elements.size();
    vector<int> dp(N,0);
    dp[0] = elements[0];
    for(int i=1;i<N;i++){
        dp[i] = dp[i-1] + elements[i];
    }
    vector<int> check(1000001,0);
    int idx = 1;
    while(idx<=N){
        for(int start=0;start<N;start++){
            int end = start + idx;
            if(end>=N){
                int value = dp[N-1] - dp[start] + dp[end-N];
                // check.push_back(value);
                if(check[value] == 0){
                    check[value]++;
                    answer++;
                }
            
                // break;
            }
            else{
                int value = dp[end] - dp[start];
                if(check[value]==0){
                    check[value]++;
                    answer++;
                }
                // check.push_back(dp[end]-dp[start]);
            }
        }
        idx++;
    }

    
    
    return answer;
}