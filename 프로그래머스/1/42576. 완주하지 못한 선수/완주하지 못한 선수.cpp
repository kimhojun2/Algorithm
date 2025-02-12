#include <string>
#include <vector>
#include <map>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    map<string,int>dic;
    for(auto p : participant){
        dic[p]++;
    }
    for(auto pp : completion){
        dic[pp]--;
    }
    for(auto ppp : dic){
        if(ppp.second !=0){
            answer = ppp.first;
            break;
        }
    }
    return answer;
}