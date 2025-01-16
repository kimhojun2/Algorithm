#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M, R;
queue<int>q;

void bfs(vector<vector<int>>& graph, vector<int>& visited,int start) {
	visited[start] = 0;
	q.push(start);

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		for (int i = 0;i < graph[now].size();i++) {
			int next = graph[now][i];
			if (visited[next] == -1) {
				visited[next] = visited[now] + 1;
				q.push(next);
			}
		}
	}
}



int main() {
	cin >> N >> M >> R;

	vector<vector<int>> graph(N+1);
	vector<int> visited(N + 1, -1);


	for (int i = 0;i < M;i++) {
		int s, e;
		cin >> s >> e;
		graph[s].push_back(e);
		graph[e].push_back(s);
	}

	bfs(graph,visited,R);
	for (int i = 1;i <= N;i++) {
		cout << visited[i] << '\n';
	}

	return 0;
}