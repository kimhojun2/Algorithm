#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <sstream>
using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    vector<vector<string>>message;
    map<string, string>name;
    for(auto now : record){
        string s,id,n;
        stringstream ss(now);
        ss >> s>>id>>n;
        if(s == "Enter"){
            message.push_back({id,s});
            name[id] = n;
        }
        else if(s == "Leave"){
            message.push_back({id,s});
            
        }
        else{
            name[id] = n;
        }
    }
    for(auto now : message){
        string nickname = name[now[0]];
        if(now[1] == "Enter"){
            answer.push_back(nickname+"님이 들어왔습니다.");
        }
        else{
            answer.push_back(nickname+"님이 나갔습니다.");
        }
        // cout << nickname<<" ";
        // cout << now[0] <<" "<<now[1]<<'\n';
    }
    return answer;
}