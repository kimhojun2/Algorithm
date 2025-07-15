#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

#define INF 987654321

int T;

pair<int, int> dijkstra(vector<vector<pair<int, int>>>& graph, int start, int n) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> distance(n + 1, INF);
    distance[start] = 0;

    pq.push({ 0, start });

    while (!pq.empty()) {
        int dist = pq.top().first;
        int now = pq.top().second;
        pq.pop();

        if (distance[now] < dist) continue;

        for (auto& edge : graph[now]) {
            int next = edge.first;
            int cost = edge.second;

            if (distance[next] > dist + cost) {
                distance[next] = dist + cost;
                pq.push({ distance[next], next });
            }
        }
    }

    int cnt = 0;
    int max_time = 0;
    for (int i = 1; i <= n; i++) {
        if (distance[i] != INF) {
            cnt++;
            max_time = max(max_time, distance[i]);
        }
    }

    return { cnt, max_time };
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    while (T--) {
        int n, d, c;
        cin >> n >> d >> c;
        vector<vector<pair<int, int>>> graph(n + 1);

        for (int i = 0; i < d; i++) {
            int a, b, s;
            cin >> a >> b >> s;
            graph[b].push_back({ a, s }); 
        }

        pair<int, int> result = dijkstra(graph, c, n);
        cout << result.first << " " << result.second << "\n";
    }

    return 0;
}
