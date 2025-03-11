#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = 0;
    queue<int>q1;
    queue<int>q2;
    long long sum1 = 0;
    long long sum2 = 0;
    for(int now : queue1){
        q1.push(now);
        sum1 += now;
    }
    for(int now : queue2){
        q2.push(now);
        sum2 += now;
    }
    
    while(sum1 != sum2){
        if(sum1 > sum2){
            q2.push(q1.front());
            sum2 += q1.front();
            sum1 -= q1.front();
            q1.pop();
        }
        else if(sum1 < sum2){
            q1.push(q2.front());
            sum1 += q2.front();
            sum2 -= q2.front();
            q2.pop();
        }
        answer++;
        if(q1.empty() || q2.empty()){
            answer = -1;
            break;
        }
        if(answer > 2*(queue1.size()+queue2.size())){
            answer=-1;
            break;
        }
    }
    
    cout << sum1 <<" "<<sum2;
    return answer;
}