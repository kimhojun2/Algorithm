#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;
queue<int> q;

vector<vector<int>>arr;
vector<int>visited;

void bfs(int start) {
	visited[start] = 1;
	q.push(start);
	
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (int i = 0;i < arr[now].size();i++) {
			int next = arr[now][i];
			if (!visited[next]) {
				visited[next] = visited[now] + 1;
				q.push(next);
			}
		}
	}

}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	arr = vector<vector<int>>(N + 1, vector<int>());
	visited = vector<int>(N + 1);
	for (int i = 0;i < M;i++) {
		int A, B;
		cin >> A >> B;
		arr[A].push_back(B);
		arr[B].push_back(A);
	}
	
	bfs(1);

	int idx = 0;
	int dist = 0; 
	int cnt = 0;

	for (int i = 2; i <= N; i++) {
		if (visited[i]-1 > dist) {
			dist = visited[i] - 1;
			idx = i;
			cnt = 1;
		}
		else if (visited[i] - 1 == dist) {
			cnt++;
		}
	}
	cout << idx<<' ' << dist<<' ' << cnt;


	return 0;
}