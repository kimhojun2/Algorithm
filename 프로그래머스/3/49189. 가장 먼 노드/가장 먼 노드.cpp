#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int bfs(int n, vector<vector<int>>& graph){
    int max = 0;
    int cnt = 0;
    queue<int>q;
    vector<int>visited(n+1,0);
    q.push(1);
    visited[1] = 1;
    while(!q.empty()){
        int now = q.front();
        q.pop();
        for(int next : graph[now]){
            if(visited[next] !=0) continue;
            visited[next] = visited[now] + 1;
            if(visited[next] > max){
                max = visited[next];
                cnt = 1;
            }
            else if(visited[next] == max) cnt++;
            q.push(next);
        }
    }
    
    return cnt;
}


int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    vector<vector<int>>graph(n+1);
    for(int i=0;i<edge.size();i++){
        vector<int>ed = edge[i];
        graph[ed[0]].push_back(ed[1]);
        graph[ed[1]].push_back(ed[0]);
    }
    answer = bfs(n,graph);
    return answer;
}