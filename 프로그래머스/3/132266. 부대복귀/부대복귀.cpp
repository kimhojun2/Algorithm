#include <string>
#include <vector>
#include <queue>
using namespace std;

void bfs(int destination, vector<vector<int>>& graph, vector<int>& visited){
    queue<int>q;
    q.push(destination);
    visited[destination] = 1;
    
    while(!q.empty()){
        int now = q.front();
        q.pop();
        for(int next : graph[now]){
            if(visited[next] == 0){
                visited[next] = visited[now] + 1;
                q.push(next);
            }
        }
    }
}

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    vector<int> answer;
    vector<vector<int>>graph(n+1);
    for(vector<int> road : roads){
        int u = road[0];
        int v = road[1];
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    vector<int>visited(n+1,0);
    bfs(destination, graph, visited);
    for(int source : sources){
        if(visited[source] == 0){
            answer.push_back(-1);
        }
        else{
            answer.push_back(visited[source]-1);
        }
    }
    return answer;
}