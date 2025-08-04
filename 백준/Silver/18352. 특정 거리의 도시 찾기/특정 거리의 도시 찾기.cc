#include <iostream>
#include <vector>
#include <queue>
using namespace std;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, M, K, X;
	cin >> N >> M >> K >> X;

	vector<vector<int>>graph(N + 1);
	for (int i = 0;i < M;i++) {
		int A, B;
		cin >> A >> B;
		graph[A].push_back(B);
	}
	queue<int>q;
	vector<int>visited(N + 1);
	q.push(X);
	visited[X] = 1;

	while (!q.empty()) {
		int now = q.front();
		q.pop();
		
		for (int next : graph[now]) {
			if (visited[next] == 0 || visited[next] > visited[now] + 1) {
				visited[next] = visited[now] + 1;
				q.push(next);
			}
		}
	}
	vector<int>ans;
	for (int i = 1;i <= N;i++) {
		if (visited[i] - 1 == K) {
			ans.push_back(i);
		}
	}
	if (!ans.empty()) {
		for (int a : ans) {
			cout << a<<'\n';
		}
	}
	else cout << -1;
	return 0;
}