#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;
    vector<int> idx(26,102);
    for(auto now : keymap){
        for(int i=0;i<now.size();i++){
            int now_idx = now[i] - 'A';
            if(i < idx[now_idx]){
                idx[now_idx] = i+1;
            }
        }
    }
    for(auto now : targets){
        int cnt = 0;
        for(auto check : now){
            int check_idx = check-'A';
            if(idx[check_idx] == 102){
                cnt = -1;
                break;
            }
            cnt += idx[check_idx];
        }
        answer.push_back(cnt);
    }
    return answer;
}