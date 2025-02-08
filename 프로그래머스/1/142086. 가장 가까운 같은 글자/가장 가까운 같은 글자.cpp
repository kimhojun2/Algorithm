#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer(s.length(), -1);
    vector<int> a(27, -1);
    for(int i=0;i<s.size();i++){
        int idx = s[i]-'a';
        if(a[idx]==-1){
            a[idx] = i;
            continue;
        }
        answer[i] = i - a[idx];
        a[idx] = i;
    }
    return answer;
}