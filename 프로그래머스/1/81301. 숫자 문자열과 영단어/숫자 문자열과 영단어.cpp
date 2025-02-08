#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

int solution(string s) {
    int answer = 0;
    int idx = 0;
    map<char,int>m ={
        {'z',0},{'o',1},{'w',2},{'h',3},{'u',4},{'o',5},{'o',6},{'o',7},{'e',8},{'n',9}
    };
    while(idx < s.size()){
        if(isdigit(s[idx])){
            int now = s[idx]-'0';
            answer *= 10;
            answer+=now;
            idx++;
        }
        else{
            char check = s[idx];
            if(check == 'z'){
                answer *= 10;
                idx +=4;
                continue;
            }
            if(check == 'o'){
                answer *= 10;
                answer+=1;
                idx +=3;
                continue;
            }
            if(check == 't'){
                if(s[idx+1] == 'w'){
                    answer *= 10;
                    answer+=2;
                    idx +=3;
                    continue;
                }
                answer *= 10;
                answer+=3;
                idx +=5;
                continue;
            }
            if(check == 'f'){
                if(s[idx+1] == 'o'){
                    answer *= 10;
                    answer+=4;
                    idx +=4;
                    continue;
                }
                answer *= 10;
                answer+=5;
                idx +=4;
                continue;
            }
            if(check == 's'){
                if(s[idx+1] == 'i'){
                    answer *= 10;
                    answer+=6;
                    idx +=3;
                    continue;
                }
                answer *= 10;
                answer+=7;
                idx +=5;
                continue;
            }
            if(check == 'e'){
                answer *= 10;
                answer+=8;
                idx +=5;
                continue;
            }
            if(check == 'n'){
                answer *= 10;
                answer+=9;
                idx +=4;
                continue;
            }
        }
    }
    return answer;
}