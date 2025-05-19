#include <iostream>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int answer = 0;

void dijkstra(vector<vector<pair<int,int>>> &graph, int N, int K){
    priority_queue<pair<int,int>>pq;
    vector<int>distance(N+1, 500001);
    distance[1] = 0;
    pq.push({0,1});
    while(!pq.empty()){
        int dist = -1*pq.top().first;
        int now = pq.top().second;
        pq.pop();
        
        if(distance[now] < dist) continue;
        for(int i=0; i<graph[now].size();i++){
            int next = graph[now][i].first;
            int d = graph[now][i].second;
            int cost = dist + d;
            if(cost<distance[next]){
                distance[next] = cost;
                pq.push({-cost,next});
            }
        }
    }
    for(auto d : distance){
        if(d<=K) answer++;
    }
}


int solution(int N, vector<vector<int> > road, int K) {
    
    vector<vector<pair<int,int>>> graph(N+1);
    for(int i=0;i<road.size();i++){
        int s,e,v;
        s = road[i][0];
        e = road[i][1];
        v = road[i][2];
        graph[s].push_back({e,v});
        graph[e].push_back({s,v});
    }
    dijkstra(graph,N,K);
    
    
    
    return answer;
}