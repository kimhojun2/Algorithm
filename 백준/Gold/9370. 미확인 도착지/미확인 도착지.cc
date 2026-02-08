#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int T;
const int INF = 1e9;

vector<int> dijkstra(int n, int s, vector<vector<pair<int, int>>>& adj) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
	vector<int>distance(n + 1, INF);
	pq.push({ 0,s });
	distance[s] = 0;

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
				pq.push({ distance[nxt], nxt });
			}
		}
	}

	return distance;
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;
	for (int tc = 0;tc < T;tc++) {
		int n, m, t;
		cin >> n >> m >> t;
		int s, g, h;
		cin >> s >> g >> h;
		vector<vector<pair<int, int>>>adj(n + 1);
		for (int i = 0;i < m;i++) {
			int a, b, d;
			cin >> a >> b >> d;
			adj[a].push_back({ b,d });
			adj[b].push_back({ a,d });
		}
		vector<int>candidate;
		for (int i = 0;i < t;i++) {
			int x;
			cin >> x;
			candidate.push_back(x);
		}
		sort(candidate.begin(), candidate.end());

		vector<int>dist1 = dijkstra(n, s, adj);//start -> end
		vector<int>dist2 = dijkstra(n, g, adj);//g -> start, g-> h, g->x
		vector<int>dist3 = dijkstra(n, h, adj);//h->start, h->x

		for (int x : candidate) {

			int path1 = dist1[g] + dist2[h] + dist3[x];
			int path2 = dist1[h] + dist2[h] + dist2[x];

			if (dist1[x] != INF && (dist1[x] == path1 || dist1[x] == path2)) {
				cout << x << " ";
			}
		}cout << '\n';

	}


	return 0;
}