#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> numbers) {
    int N = numbers.size();
    vector<int> answer(N,-1);
    priority_queue<int>pq;
    for(int i = N-1;i>=0;i--){
        while (!pq.empty() && numbers[i]>= -1*pq.top()) {
            pq.pop();
        }
        if(!pq.empty()){
            answer[i] = -1 * pq.top();
        }
        pq.push(-1*numbers[i]);
    }
    return answer;
}