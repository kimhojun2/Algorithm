#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 1;
    int idx = 1;
    int cnt=1;
    char c = s[0];
    while(idx<s.size()){
        char now = s[idx];
        if(cnt==0){
            c = now;
            cnt=1;
            answer++;
        }
        else if(now == c) cnt++;
        
        else cnt--;
        
        idx++;
    }
    return answer;
}