#include <string>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

int solution(int n) {
    int answer = 0;
    
    queue<int> q;
    int idx = 0;
    while(n!=0){
        q.push(n%3);
        n/=3;
        idx++;
    }

    while(!q.empty()){
        idx--;
        answer += pow(3,idx)*q.front();
        q.pop();
    }
    
    return answer;
}