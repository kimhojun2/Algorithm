#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N, M;

int distance_nodes(int start, int end, vector<vector<pair<int,int>>> &graph) {
	vector<int> dist(N + 1, -1);
	queue<int> q;
	dist[start] = 0;
	q.push(start);
	while (!q.empty()) {
		int u = q.front(); q.pop();
		if (u == end) break;
		for (auto& nx : graph[u]) {
			int v = nx.first, w = nx.second;
			if (dist[v] == -1) {
				dist[v] = dist[u] + w;
				q.push(v);
			}
		}
	}

	return dist[end];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;


	vector<vector<pair<int, int>>>graph(N + 1);
	for (int i = 0;i < N - 1;i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back({ b,c });
		graph[b].push_back({ a,c });
	}

	while (M--) {
		int start, end;
		cin >> start >> end;

		int ans = distance_nodes(start, end, graph);
		cout << ans<<'\n';
	}

	return 0;
}