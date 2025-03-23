#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;
    if(n>s) return {-1};
    int idx = n;
    while(idx>0){
        answer.push_back(s/n);
        idx--;
    }
    int remain = s- (s/n)*n;
    int now=answer.size()-1;
    while(remain>0){
        answer[now]++;
        remain--;
        now--;
    }
    return answer;
}