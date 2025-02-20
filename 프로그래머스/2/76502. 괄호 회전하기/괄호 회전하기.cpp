#include <string>
#include <vector>
#include <stack>
#include <iostream>
#include <algorithm>
using namespace std;


bool check(string str) {
    stack<char> s;
    for(char now : str) {
        if(now == '[' || now == '{' || now == '(') {
            s.push(now);
        } else {
            if(s.empty()) return false;
            if(s.top() == '[' && now != ']') return false;
            if(s.top() == '{' && now != '}') return false;
            if(s.top() == '(' && now != ')') return false;
            s.pop();
        }
    }
    return s.empty();
}

int solution(string s) {
    int answer = 0;
    string rotated = s;
    for(int i = 0; i < s.size(); i++) {
        if(check(rotated)) answer++;
        rotate(rotated.begin(), rotated.begin() + 1, rotated.end());
    }
    return answer;
}
