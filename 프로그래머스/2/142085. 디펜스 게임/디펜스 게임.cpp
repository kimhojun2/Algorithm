#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int n, int k, vector<int> enemy) {
    int answer = 0;
    priority_queue<int>pq;
    int total = 0;
    for(int i=0; i<enemy.size();i++){
        int now = enemy[i];
        pq.push(now);
        total += now;
        if(total>n){
            if(k>0){
                total -= pq.top();
                pq.pop();
                k--;
            }
            else{
                break;
            }
        }
        answer++;
    }
    return answer;
}