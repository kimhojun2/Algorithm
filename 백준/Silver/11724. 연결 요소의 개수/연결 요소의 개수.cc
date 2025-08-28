#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void bfs(int start, vector<vector<int>> &graph,vector<bool>& visited) {
	queue<int>q;
	q.push(start);

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		for (int i = 0;i < graph[now].size();i++) {
			int next = graph[now][i];
			if (!visited[next]) {
				visited[next] = true;
				q.push(next);
			}
		}

	}

}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, M;
	cin >> N >> M;

	vector<vector<int>>graph(N + 1);

	for (int i = 0;i < M;i++) {
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	vector<bool>visited(N + 1, false);
	int ans = 0;
	for (int i = 1;i <= N;i++) {
		if (!visited[i]) {
			ans++;
			visited[i] = true;
			bfs(i, graph, visited);
		}
	}

	cout << ans;

	return 0;
}