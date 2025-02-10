#include <string>
#include <vector>

using namespace std;

string solution(string s, string skip, int index) {
    string answer = "";
    vector<int> num(26,0);
    for(auto now : skip){
        int iii = now -'a';
        num[iii]++;
    }
    for(int i=0;i<s.size();i++){
        int cnt = 0;
        int n = s[i] - 'a';
        while(cnt<index){
            n = (n + 1) % 26;
            if (num[n] == 0){
                cnt++;
            }
        }
        answer += char(n+'a');
    }
    return answer;
}