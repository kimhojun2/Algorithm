#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;

bool compare(pair<string, int>& A, pair<string, int>& B){
    
    return A.second > B.second;
}

bool compare2(pair<int, int>& A, pair<int, int>& B){
    
    return A.second > B.second;
}


vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string,int>dic;
    map<string,vector<pair<int,int>>>lst;
    
    for(int i=0;i<genres.size();i++){
        string genre = genres[i];
        int time = plays[i];
        dic[genre] += time;
        lst[genre].push_back({i,time});
    }
    
    vector<pair<string, int>>v = {dic.begin(), dic.end()};
    sort(v.begin(), v.end(), compare);
    for(auto it : v){
        string gen = it.first;
        int idx = 0;
        sort(lst[gen].begin(), lst[gen].end(), compare2);
        for(int i=0;i<lst[gen].size();i++){
            if(i==2) break;
            answer.push_back(lst[gen][i].first);
        }
    }
    
    return answer;
}