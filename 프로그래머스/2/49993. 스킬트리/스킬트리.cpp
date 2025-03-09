#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    map<char,int>dic;
    int idx = 1;
    for(int i=0;i<skill.size();i++){
        dic[skill[i]] = idx;
        idx++;
    }
    for(auto tree : skill_trees){
        int order = 1;
        bool tf = true;
        for(int i=0;i<tree.size();i++){
            if(dic.find(tree[i]) == dic.end()) continue;
            if(dic[tree[i]] != order){
                tf = false;
                break;
            }
            order++;
        }
        if(tf) answer++;
    }
    return answer;
}