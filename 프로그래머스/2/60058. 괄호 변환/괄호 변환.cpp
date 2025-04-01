#include <string>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;

bool check(string u) {
    stack<char>s;
    
    for(auto c: u) {
        if(c == '('){
            s.push(c);
        }
        else {
            if(s.empty()) return false;
            s.pop();
        }
    }
    if(s.empty()) return true;
    return false;
}


string solution(string p) {
    string answer = "";
    
    //  step1
    if(p==""){
        return answer;
    }
    
    //  step2
    int open = 0;
    int close = 0;
    string u="";
    string v="";
    for(int i=0;i < p.size();i++){
        if(p[i] == '('){
            open++;
        }
        else{
            close++;
        }
        if(open == close){
            u = p.substr(0, i+1);
            v = p.substr(i+1);
            break;
        }
    }
    
    //  step3
    if(check(u)){
        answer = u + solution(v);
    }
    
    //  step4
    else{
        answer = "(" + solution(v) +")";
        for(int i=1; i<u.size()-1; i++) {
            if (u[i] == '(') {
                answer += ')';
            } else {
                answer += '(';
            }
    
        }
    }
    return answer;
}