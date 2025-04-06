#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;

map<string, int>dic = {
    {"diamond",0},
    {"iron",1},
    {"stone",2}
};


bool comapre(vector<int>& A, vector<int>& B){
    if(A[0]==B[0]){
        if(A[1]==B[1]){
            return A[2] >B[2];
        }
        return A[1]>B[1];
    }
    return A[0] > B[0];
}

int solution(vector<int> picks, vector<string> minerals) {
    int answer = 0;
    vector<vector<int>>arr;
    int sum = 0;
    for(int pick : picks) sum += pick;
    cout << sum<<'\n';
    int idx=0;
    while(idx<minerals.size() && sum>0){
        vector<int>ans(3,0);
        if(idx+5<minerals.size()){
            
            for(int i=0;i<5;i++){
                string now = minerals[idx+i];
                ans[dic[now]]++;
            }
            arr.push_back(ans);
            idx+=5;
            sum--;
        }
        else{
            int now_idx = idx;
            while(now_idx<minerals.size()){
                ans[dic[minerals[now_idx]]]++;
                now_idx++;
            }
            arr.push_back(ans);
            break;
            
        }
    }
    
    sort(arr.begin(), arr.end(), comapre);
    
    int now_pick = 0;
    for(auto now : arr){
        while(picks[now_pick]<=0){
            now_pick++;
        }
        picks[now_pick]--;
        if(now_pick==0){
            answer += (now[0]*1+now[1]*1+now[2]*1);
        }
        else if(now_pick==1){
            answer += (now[0]*5+now[1]*1+now[2]*1);
        }
        else{
            answer += (now[0]*25+now[1]*5+now[2]*1);
        }
    }
    
    return answer;
}