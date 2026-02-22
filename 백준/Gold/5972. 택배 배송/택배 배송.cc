#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int N, M;

int dijkstra(vector<vector<pair<int,int>>>& adj) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
	const int INF = 1e9;
	vector<int>distance(N + 1, INF);
	distance[1] = 0;
	pq.push({ 0,1 });

	while (!pq.empty()) {
		int curr = pq.top().second;
		int dist = pq.top().first;
		pq.pop();

		if (dist > distance[curr]) continue;
		for (int i = 0;i < adj[curr].size();i++) {
			int nxt = adj[curr][i].first;
			int cost = adj[curr][i].second;
			if (distance[nxt] > dist + cost) {
				distance[nxt] = dist + cost;
				pq.push({ distance[nxt],nxt });
			}
		}
	}

	return distance[N];
}



int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;

	vector<vector<pair<int, int>>>adj(N+1);
	for (int i = 0;i < M;i++) {
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back({ b,c });
		adj[b].push_back({ a,c });
	}

	cout << dijkstra(adj);


	return 0;
}