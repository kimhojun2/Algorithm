#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
using namespace std;

map<int, char>dic = {
    {10,'A'},
    {11,'B'},
    {12,'C'},
    {13,'D'},
    {14,'E'},
    {15,'F'} 
};


string change_num(int n, int num){
    if(num == 0) return "0";
    
    stack<int>s;
    while(num!=0){
        s.push(num%n);
        num /=n;
    }
    
    string change = "";    
    while(!s.empty()){
        if(s.top()>=10){
            change += dic[s.top()];
        }
        else{
            change += to_string(s.top());
        }
        s.pop();
    }
    
    return change;
}


string solution(int n, int t, int m, int p) {
    string answer = "";
    int now = 0;
    int cnt = 0;
    int total = 0;
    while(cnt < t){
        //  1. 진법으로 변환
        string string_num = change_num(n,now);
        
        //  2. 변환 된 숫자로 길이 구하기
        int L = string_num.length();
        
        //  3. 알맞은 순서 구하기
        for (int i = 0; i < L; i++) {
            if (total % m == (p - 1)) {
                answer += string_num[i];
                cnt++;
                if (cnt == t) return answer;
            }
            total++;
        }
        now++;
    }
    
    return answer;
}