#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

int idx;
bool compare(vector<int> &a, vector<int> &b) {
    return a[idx] < b[idx];  
}

vector<vector<int>> solution(vector<vector<int>> data, string ext, int val_ext, string sort_by) {
        vector<vector<int>> answer;
    map<string,int> m ={
        {"code",0},
        {"date",1},
        {"maximum",2},
        {"remain",3}
    };
    idx = m[sort_by];
    for(int i=0;i<data.size();i++){
        if(data[i][m[ext]] < val_ext){
            answer.push_back(data[i]);
        }
    }
    sort(answer.begin(),answer.end(), compare);
    // for(auto now : answer){
    //     for(auto next: now){
    //         cout << next <<'\n';
    //     }
    // }
    
    return answer;
}