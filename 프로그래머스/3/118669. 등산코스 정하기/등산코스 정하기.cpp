#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

const int INF = 1e9;

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
    vector<vector<pair<int,int>>> graph(n+1);
    vector<int> intensity(n+1, INF);
    vector<bool> isSummit(n+1, false);

    for (auto s : summits) isSummit[s] = true;

    for (auto path : paths) {
        int a = path[0], b = path[1], w = path[2];
        graph[a].push_back({b, w});
        graph[b].push_back({a, w});
    }

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;

    for (int gate : gates) {
        intensity[gate] = 0;
        pq.push({0, gate});
    }

    while (!pq.empty()) {
        auto [cost, now] = pq.top(); pq.pop();

        if (cost > intensity[now]) continue;
        if (isSummit[now]) continue;

        for (auto [next, weight] : graph[now]) {
            int maxCost = max(intensity[now], weight);
            if (intensity[next] > maxCost) {
                intensity[next] = maxCost;
                pq.push({maxCost, next});
            }
        }
    }

    int minIntensity = INF;
    int minSummit = 0;
    sort(summits.begin(), summits.end());

    for (int s : summits) {
        if (intensity[s] < minIntensity) {
            minIntensity = intensity[s];
            minSummit = s;
        }
    }

    return {minSummit, minIntensity};
}
