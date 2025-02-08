#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int idx;
bool compare(string &a, string &b){
    if (a[idx]==b[idx]){
        return a<b;
    }
    return a[idx] < b[idx];
}
vector<string> solution(vector<string> strings, int n) {
    vector<string> answer;
    idx = n;    
    sort(strings.begin(), strings.end(), compare);
    for(auto now : strings){
        answer.push_back(now);
    }
    return answer;
}