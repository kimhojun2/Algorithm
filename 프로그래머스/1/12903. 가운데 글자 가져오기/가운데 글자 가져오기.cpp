#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    int L = s.size();
    if(s.length()%2==0)
        answer+=s[L/2-1];
    answer +=s[L/2];
    return answer;
}