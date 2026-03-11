#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int N, M, K;

struct Node {
	long long d;
	int pos, k;

	bool operator>(const Node& other) const {
		return d > other.d;
	}
};

const long long INF = 1e15;

long long dijkstra(vector<vector<pair<int,int>>>& adj) {
	vector<vector<long long>>distance(N + 1, vector<long long>(K + 1, INF));
	priority_queue<Node, vector<Node>, greater<Node>>pq;
	pq.push({ 0,1,0 });
	distance[1][0] = 0;

	while (!pq.empty()) {
		int curr = pq.top().pos;
		int k = pq.top().k;
		long long dist = pq.top().d;
		pq.pop();
		
		if (dist > distance[curr][k]) continue;
		for (int i = 0;i < adj[curr].size();i++) {
			int nxt = adj[curr][i].first;
			long long cost = adj[curr][i].second;
			if (distance[nxt][k] > cost + dist) {
				distance[nxt][k] = cost + dist;
				pq.push({ distance[nxt][k],nxt,k });
			}
			if (k < K) {
				if (distance[nxt][k + 1] > dist) {
					distance[nxt][k + 1] = dist;
					pq.push({ distance[nxt][k + 1],nxt,k + 1 });
				}
			}
		}
	}
	long long ans = INF;
	for (int i = 0;i <= K;i++) {
		ans = min(ans, distance[N][i]);
	}

	return ans;
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M >> K;

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