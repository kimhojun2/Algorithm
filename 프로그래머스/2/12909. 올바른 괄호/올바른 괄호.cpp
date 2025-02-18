#include<string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    stack<char> ss;
    for(auto now : s){
        if(ss.empty()){
            if(now == '('){
                ss.push(now);
            }
            else{
                answer = false;
                break;
            }
        }else{
            if(now == '(') ss.push(now);
            else ss.pop();
        }
    }
    if(!ss.empty()) answer = false;

    return answer;
}