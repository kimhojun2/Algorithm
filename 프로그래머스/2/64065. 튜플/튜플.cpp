#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

bool compare(pair<int, int> &a, pair<int,int> &b){
    return a.second > b.second;
}

vector<int> solution(string s) {
    vector<int> answer;
    string num = "";
    map<int,int>dic;
    for(auto now : s){
        if(now>='0' && now<='9'){
            num += now;
        }
        else{
            if(num !=""){
                // if(now ==','){
                //     continue;
                // }
                int new_num = stoi(num);
                if(dic.find(new_num) == dic.end()){
                    dic[new_num] = 1;  
                }
                else{
                    dic[new_num]++;
                }
                num ="";
            }
        }
    }
    vector<pair<int,int>>result;
    for(auto it : dic){
        result.push_back(it);
    }
    sort(result.begin(),result.end(),compare);
    for(auto now : result){
        answer.push_back(now.first);
    }
    
    return answer;
}