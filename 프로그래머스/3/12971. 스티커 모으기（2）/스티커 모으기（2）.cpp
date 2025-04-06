#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> sticker)
{
    int answer =0;
    int N = sticker.size();
    if(N==1) return sticker[0];
    vector<int>dp1(N+1,0);
    vector<int>dp2(N+1,0);
    dp1[0] = sticker[0];
    dp1[1] = dp1[0];
    for(int i=2;i<N-1;i++){
        dp1[i] = max(dp1[i-1], dp1[i-2] + sticker[i]);
    }
    dp2[0] = 0;
    dp2[1] = sticker[1];
    for(int i=2;i<N;i++){
        dp2[i] = max(dp2[i-1], dp2[i-2] + sticker[i]);
    }
    
    answer = max(dp1[N-2], dp2[N-1]);
    
    
    return answer;
    
}