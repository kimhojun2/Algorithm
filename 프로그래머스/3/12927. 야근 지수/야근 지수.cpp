#include <string>
#include <vector>
#include <queue>

using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    priority_queue<int>pq;
    for(auto  work : works){
        pq.push(work);
    }
    
    while(n > 0 && !pq.empty()){
        int now = pq.top();
        pq.pop();
        if(now>0){
            pq.push(now-1);
            n--;
        }
    }
    
    while (!pq.empty()) {
        int now = pq.top();
        pq.pop();
        answer += (long long)now * now;
    }
    
    return answer;
}