#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

queue<int>q;

void bfs(int start, vector<vector<int>>& graph, vector<vector<int>>& check){
    q.push(start);
    while(!q.empty()){
        int now = q.front();
        q.pop();
        for(int next : graph[now]){
            if(check[start][next] == 1) continue;
            check[start][next] = 1;
            q.push(next);
        }
    }
}

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    vector<vector<int>>check(n+1, vector<int>(n+1,0));
    vector<vector<int>>graph(n+1);
    for(vector<int> result : results){
        graph[result[0]].push_back(result[1]);
    }
    for(int i=1;i<=n;i++){
        bfs(i, graph, check);
    }
    for(int i=1; i<=n;i++){
        bool tf = true;
        for(int j=1; j<=n;j++){
            if(i==j) continue;
            if(check[i][j] == 0 && check[j][i] == 0){
                tf = false;
                break;
            }
        }
        if(tf) answer++;
    }
    return answer;
}