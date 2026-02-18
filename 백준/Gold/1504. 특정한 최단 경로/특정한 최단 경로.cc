#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int N, E;
int v1, v2;

const int INF = 1e9;

vector<int> dijkstra(int start, vector<vector<pair<int, int>>>& adj) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
	vector<int>distance(N + 1, INF);
	pq.push({ 0,start });
	distance[start] = 0;

	while (!pq.empty()) {
		int curr = pq.top().second;
		int dist = pq.top().first;
		pq.pop();

		if (dist > distance[curr]) continue;
		for (int i = 0;i < adj[curr].size();i++) {
			int nxt = adj[curr][i].first;
			int cost = adj[curr][i].second;
			if (distance[nxt] > cost + dist) {
				distance[nxt] = cost + dist;
				pq.push({ distance[nxt],nxt });
			}
		}
	}

	return distance;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> E;
	vector<vector<pair<int, int>>>adj(N + 1);
	for (int i = 0;i < E;i++) {
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back({ b,c });
		adj[b].push_back({ a,c });
	}
	cin >> v1 >> v2;

	vector<int>dist_v1(N + 1);
	vector<int>dist_v2(N + 1);
	dist_v1 = dijkstra(v1, adj);
	dist_v2 = dijkstra(v2, adj);

	long long path1 = (long long)dist_v1[1] + dist_v1[v2] + dist_v2[N];
	long long path2 = (long long)dist_v2[1] + dist_v2[v1] + dist_v1[N];

	long long ans = min(path1, path2);

	if (ans >= INF) cout << -1;
	else cout << ans;
	return 0;
}