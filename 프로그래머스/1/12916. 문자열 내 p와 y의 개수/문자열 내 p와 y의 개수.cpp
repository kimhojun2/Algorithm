#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    bool answer = true;
    int p = 0;
    int y = 0;
    for(int i=0;i<s.length();i++){
        char now = s[i];
        if(now=='p'||now=='P'){
            p++;
        }
        else if(now=='y'||now=='Y'){
            y++;
        }
    }
    if(y!=p){
        answer = false;
    }

    return answer;
}