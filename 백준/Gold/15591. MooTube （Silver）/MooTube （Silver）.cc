#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int N, Q;



int bfs(vector<vector<pair<int, int>>>& adj, int start, int k) {
	queue<int>q;
	q.push(start);
	vector<bool>visited(N + 1, false);
	visited[start] = true;

	int result = 0;

	while (!q.empty()) {
		int curr = q.front();
		q.pop();

		for (int i = 0;i < adj[curr].size();i++) {
			int nxt = adj[curr][i].first;
			int usado = adj[curr][i].second;
			if (visited[nxt]) continue;
			if (usado >= k) {
				result++;
				q.push(nxt);
				visited[nxt] = true;
			}
		}
	}

	return result;
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> Q;

	vector<vector<pair<int, int>>>adj(N + 1);
	for (int i = 0;i < N - 1;i++) {
		int p, q, r;
		cin >> p >> q >> r;
		adj[p].push_back({ q,r });
		adj[q].push_back({ p,r });
	}

	for (int i = 0;i < Q;i++) {
		int k, v;
		cin >> k >> v;
		cout << bfs(adj, v, k) << '\n';
	}
	

	return 0;
}