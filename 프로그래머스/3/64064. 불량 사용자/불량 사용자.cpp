#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
#include <set>
using namespace std;

map<set<string>,int>dic;


void dfs(vector<vector<string>> ans, set<string> lst, int level){
    if(level == ans.size()){
        dic[lst]++;
        return;
    }
    for(int i=0; i<ans[level].size();i++){
        
        if (lst.find(ans[level][i]) != lst.end()) continue;
        lst.insert(ans[level][i]);
        dfs(ans,lst,level+1);
        lst.erase(ans[level][i]);
    }
}


int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;
    vector<vector<string>>ans(banned_id.size());
    for(int i=0; i<banned_id.size();i++){
        string now = banned_id[i];
        // cout << now<<'\n';
        for(int j=0; j<user_id.size();j++){
            string check = user_id[j];
            if(check.size() != now.size()) continue;
            int idx = 0;
            bool tf = true;
            while(idx < check.size() && idx < now.size()){
                if(check[idx] != now[idx] && now[idx] !='*'){
                    tf = false;
                    break;
                }
                idx++;
            }
            if(tf){
                ans[i].push_back(check);
            }
            
        }
    }
    dfs(ans, {}, 0);
    answer = dic.size();
    return answer;
}