#include <string>
#include <vector>

using namespace std;

bool solution(string s) {
    bool answer = true;
    if(s.size()!=4 && s.size()!=6){
        answer = false;
        return answer;
    }
    for(int i=0;i<s.size();i++){
        int now = s[i];
        if(now<48||now>57){
            answer = false;
            return answer;
        }
    }
    return answer;
}