#include <string>
#include <vector>
#include <cctype>
using namespace std;

string solution(string s) {
    string answer = "";
    bool first = true;
    for(auto now : s){
        if(first){
            if(now >= 'a' && now<='z'){
                answer += toupper(now);
            }else answer += now;
            first = false;
            if(now == ' '){
                first = true;
            }
        }
        else{
            if(now == ' '){
                first = true;
                answer += now; 
            }
            else{
                if(now>='A' && now<='Z'){
                    answer += tolower(now);
                }else answer += now;
            }
        }
        
    }
    return answer;
}