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
            for(int j = 0;j<computers[now].size();j++){
                if(computers[now][j] != 1) continue;
                if(visited[j]) continue;
                q.push(j);
                visited[j] = true;
            }
        }
        answer++;
    }
    return answer;
}