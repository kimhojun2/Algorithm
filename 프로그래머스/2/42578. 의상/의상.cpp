#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 0;
    map<string, int> dic;
    for(int i=0;i<clothes.size();i++){
        string name = clothes[i][0];
        string idx = clothes[i][1];
        dic[idx]++;
    }
    int count = 1;
    for(auto it : dic){
        count *= (it.second+1);
    }
    answer = count-1;
    
    return answer;
}