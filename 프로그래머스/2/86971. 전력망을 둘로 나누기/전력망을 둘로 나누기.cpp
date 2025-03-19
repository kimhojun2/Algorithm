#include <string>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

int check(int idx, int n, vector<vector<int>>& graph){
    int cnt = 1;
    vector<int>visited(n+1,0);
    queue<int> q;
    q.push(idx);
    visited[idx] = 1;
    
    while(!q.empty()){
        int now = q.front();
        q.pop();
        for(int next : graph[now]){
            if(!visited[next]){
                visited[next] = 1;
                q.push(next);
                cnt++;
            }
        }
    }

    return cnt;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = n;
    for(int i=0;i<n-1;i++){
        vector<vector<int>>graph(n+1);
        for(int j=0;j<n-1;j++){
            if(i==j) continue;
            graph[wires[j][0]].push_back(wires[j][1]);
            graph[wires[j][1]].push_back(wires[j][0]);
        }
        int now_ans = check(1, n, graph);
        int new_ans = n - now_ans;
        answer = min(answer, abs(now_ans - new_ans));
    }
    return answer;
}