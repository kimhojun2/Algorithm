#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<vector<int>>graph;
vector<int>visited;
queue<int>q;
int step = 1;

void BFS(int start) {
	visited[start] = step;
	q.push(start);

	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (int i = 0;i < graph[now].size();i++) {
			int next = graph[now][i];
			if (!visited[next]) {
				step++;
				visited[next] = step;
				q.push(next);
			}
		}
	}
}



int main() {
	int N, M, R;
	cin >> N >> M >> R;
	graph = vector<vector<int>>(N + 1);
	visited = vector<int>(N + 1, 0);
	for (int i = 0;i < M;i++) {
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	for (int i = 1;i <= N;i++) {
		sort(graph[i].begin(), graph[i].end());
	}

	BFS(R);

	for (int i = 1;i <= N;i++) {
		cout << visited[i] << '\n';
	}

	return 0;
}