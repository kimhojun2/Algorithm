#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    sort(tangerine.begin(),tangerine.end());
    vector<int> check;
    int count = 0;
    int before = tangerine[0];
    for(auto now : tangerine){
        if(now==before){
            count++;
        }
        else{
            check.push_back(count);
            count = 1;
            before = now;
        }
    }
    check.push_back(count);
    sort(check.begin(),check.end(),greater());
    for(auto now : check){
        k-=now;
        answer++;
        if(k<=0)break;
    }
    return answer;
}