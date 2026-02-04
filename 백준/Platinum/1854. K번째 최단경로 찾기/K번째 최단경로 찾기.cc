#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int n, m, k;

void dijkstra(vector<vector<pair<int,int>>>& adj) {
	priority_queue<pair<int, int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
	vector<priority_queue<int>>distance(n+1);
	pq.push({ 0,1 });
	distance[1].push(0);

	while (!pq.empty()) {
		int curr = pq.top().second;
		int dist = pq.top().first;
		pq.pop();

		if (distance[curr].size() == k && distance[curr].top() < dist)continue;
		for (int i = 0;i < adj[curr].size();i++) {
			int nxt = adj[curr][i].first;
			int cost = adj[curr][i].second;
			if (distance[nxt].size() < k) {
				distance[nxt].push(dist + cost);
				pq.push({ dist + cost,nxt });
			}
			else if (distance[nxt].top() > dist + cost) {
				distance[nxt].pop();
				distance[nxt].push(dist+cost);
				pq.push({ dist + cost,nxt });
			}
		}
	}

	for (int i = 1;i <= n;i++) {
		if (distance[i].size() < k) cout << -1;
		else cout << distance[i].top();
		cout << '\n';
	}


}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> k;
	vector<vector<pair<int, int>>>adj(n+1);
	for (int i = 0;i < m;i++) {
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back({ b,c });
	}

	dijkstra(adj);


	return 0;
}