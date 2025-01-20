#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;

int bfs(vector<vector<int>>& arr, int start) {
	int sum=0;
	queue<int>q;
	vector<int>visited(N + 1, -1);
	q.push(start);
	visited[start] = 0;

	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (int i = 0;i < arr[now].size();i++) {
			int next = arr[now][i];
			if (visited[next] == -1) {
				visited[next] = visited[now] + 1;
				q.push(next);
			}
		}
	}

	for (int i = 1;i <= N;i++) {
		if (visited[i] != -1) {
			sum += visited[i];
		}
	}

	return sum;
}



int main() {
	cin >> N >> M;
	vector<vector<int>>arr(N + 1);
	for (int i = 0;i < M;i++) {
		int s, e;
		cin >> s >> e;
		arr[s].push_back(e);
		arr[e].push_back(s);
	}
	int min_value = 1e9;
	int ans = -1;
	for (int i = 1;i <= N;i++) {
		int value = bfs(arr, i);
		if (value < min_value) {
			min_value = value;
			ans = i;
		}
	}

	cout << ans;

	return 0;
}