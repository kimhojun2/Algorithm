#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int>pq;
    for(int i=0;i<scoville.size();i++){
        pq.push(-1 * scoville[i]);
    }
    // while(!pq.empty()){
    //     cout << pq.top();
    //     pq.pop();
    // }
   while (pq.size() > 1 && -pq.top() < K) {
        int A = -pq.top(); 
        pq.pop();
        
        int B = -pq.top(); 
        pq.pop();
        
        int newScoville = A + (B * 2); 
        pq.push(-newScoville); 
        
        answer++;
    }
    
    if (-pq.top() < K) {
        answer = -1;
    }
    
    return answer;
}