#include <iostream>
#include <string>
#include <stack>
using namespace std;

int solution(string s)
{
    int answer = 0;
    string check= "";
    int idx = -1;
    for(auto now : s){
        if(check == ""){
            check+=now;
            idx++;
        }
        else{
            if(check[idx]==now){
                check.erase(idx,1);
                idx--;
            }
            else{
                check +=now;
                idx++;
            }
        }
    }
    if(check=="") answer = 1;
    cout << check;
    return answer;
}