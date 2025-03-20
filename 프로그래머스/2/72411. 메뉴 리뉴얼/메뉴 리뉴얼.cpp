#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

map<string,int>dic;

void check(int idx, string now, string menu){
    for(int i=idx;i<menu.size();i++){
        if(now.size()>=1) dic[now+menu[i]]++;
        check(i+1,now+menu[i],menu);
    }
}


vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;

    for(int i=0;i<orders.size();i++){
        string now = orders[i];
        sort(now.begin(), now.end());
        check(0,"",now);
    }
    // check(0,"",orders[0]);
    vector<vector<pair<int,string>>>ans(11);
    for(auto it : dic){
        cout << it.second<<" "<< it.first<<'\n';
        if(it.second < 2) continue;
        for(int l : course){
            // 주어진 세트 메뉴 길이와 같고
            if(it.first.size()==l){
                // 처음이면 그대로 넣고
                if(ans[l].empty()){
                    ans[l].push_back({it.second, it.first});
                }
                //  처음이 아닌데
                else{
                    // 이전 값들보다 빈도가 많으면 새로 갱신
                    if(ans[l][0].first<it.second){
                        ans[l] = {{it.second, it.first}};
                    }
                    // 이전 값들과 빈도가 같으면 추가
                    else if(ans[l][0].first==it.second){
                        ans[l].push_back({it.second, it.first});
                    }
                }
                break;
            }
        }
    }
    
    for(int i=0;i<ans.size();i++){
        sort(ans.begin(), ans.end(), greater());
        for(int j=0;j<ans[i].size();j++){
            answer.push_back(ans[i][j].second);
        }
    }
    sort(answer.begin(), answer.end());
    
    return answer;
}