#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

#define inf 987654321

int N, M, X;

vector<int> dijkstra(vector<vector<pair<int, int>>>& graph, int start) {
    vector<int> distance(N + 1, inf);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({ 0, start });
    distance[start] = 0;

    while (!pq.empty()) {
        int dist = pq.top().first;
        int now = pq.top().second;
        pq.pop();

        if (distance[now] < dist) continue;

        for (auto& next : graph[now]) {
            int next_node = next.first;
            int cost = dist + next.second;

            if (cost < distance[next_node]) {
                distance[next_node] = cost;
                pq.push({ cost, next_node });
            }
        }
    }

    return distance;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> X;

    int s, e, v;
    vector<vector<pair<int, int>>> graph(N + 1);
    vector<vector<pair<int, int>>> reverse_graph(N + 1);

    for (int i = 0; i < M; i++) {
        cin >> s >> e >> v;
        graph[s].push_back({ e, v });
        reverse_graph[e].push_back({ s, v }); 
    }

    vector<int> toX = dijkstra(reverse_graph, X); 
    vector<int> fromX = dijkstra(graph, X);       

    int max_dist = 0;
    for (int i = 1; i <= N; i++) {
        max_dist = max(max_dist, toX[i] + fromX[i]);
    }

    cout << max_dist << '\n';

    return 0;
}
