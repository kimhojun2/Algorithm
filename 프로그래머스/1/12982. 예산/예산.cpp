#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> d, int budget) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i : d){
        pq.push(i);
    }
    while(!pq.empty()){
        if(pq.top()<=budget){
            answer++;
            budget-=pq.top();
            pq.pop();
        }
        else break;
    }
    return answer;
}