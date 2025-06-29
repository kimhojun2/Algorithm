#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

#define MAX 1e9

int V, E, K;

void dijkstra(vector<vector<pair<int,int>>>& graph) {
	priority_queue<pair<int, int>>pq;
	pq.push({ 0,K });
	
	vector<int>distance(V + 1, MAX);
	distance[K] = 0;


	while (!pq.empty()) {
		int now = pq.top().second;
		int dist = -pq.top().first;
		pq.pop();
		
		if (distance[now] < dist) continue;

		for (int i = 0;i < graph[now].size();i++) {
			int next = graph[now][i].second;
			int cost = graph[now][i].first + dist;
			if (distance[next] > cost) {
				distance[next] = cost;
				pq.push({ -cost,next });
			}
		}

	}

	for (int i = 1;i <= V;i++) {
		if (distance[i] == MAX) {
			cout << "INF" << '\n';
		}
		else {
			cout << distance[i] << '\n';
		}
	}

}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> V >> E;
	cin >> K;

	vector<vector<pair<int, int>>>graph(V+1);

	for (int i = 0;i < E;i++) {
		int u, v, w;
		cin >> u >> v >> w;
		graph[u].push_back({ w,v });
	}

	dijkstra(graph);

	return 0;
}