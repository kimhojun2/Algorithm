#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    bool visited[200] = {false,};
    queue<int>q;
    for(int i=0;i<n;i++){
        if(visited[i]) continue;
        q.push(i);
        visited[i] = true;
        while(!q.empty()){
            int now = q.front();
            q.pop();
            for(int next = 0;next<computers[now].size();next++){
                if(computers[now][next] !=1) continue;
                if(visited[next]) continue;
                q.push(next);
                visited[next] = true;
            }
        }
        answer++;
    }
    return answer;
}