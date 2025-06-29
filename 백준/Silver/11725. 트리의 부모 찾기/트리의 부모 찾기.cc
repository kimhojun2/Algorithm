#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N;

vector<int> bfs(vector<vector<int>>& graph) {
	queue<int>q;
	vector<int>visited(N+1, 0);
	visited[1] = 1;
	q.push(1);
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (int i = 0;i < graph[now].size();i++) {
			if (visited[graph[now][i]] == 0) {
				visited[graph[now][i]] = now;
				q.push(graph[now][i]);
			}
		}

	}

	return visited;
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	vector<vector<int>>graph(N+1);

	for (int i = 0;i < N - 1;i++) {
		int A, B;
		cin >> A >> B;
		graph[A].push_back(B);
		graph[B].push_back(A);
	}

	vector<int> ans = bfs(graph);

	for (int i = 2;i <= N;i++) {
		cout << ans[i] << '\n';
	}

	return 0;
}