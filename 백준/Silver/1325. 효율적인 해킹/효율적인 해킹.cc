#include <iostream>
#include <queue>
#include <vector>
using namespace std;


int bfs(vector<vector<int>>& arr, vector<int>& visited, queue<int>& q, int start) {
	q.push(start);
	visited[start] = 1;
	int cnt = 1;
	while (!q.empty()) {
		int now = q.front();
		q.pop();

		for (int i = 0;i < arr[now].size();i++) {
			int next = arr[now][i];
			if (!visited[next]) {
				cnt++;
				visited[next] = 1;
				q.push(next);
			}
		}
	}
	return cnt;
}



int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int N, M;
	cin >> N >> M;

	vector<vector<int>> arr(N + 1);
	vector<int> visited(N + 1, 0);
	queue<int> q;


	for (int i = 0;i < M;i++) {
		int A, B;
		cin >> A >> B;
		arr[B].push_back(A);
	}

	int max = 0;
	vector<int>ans;
	for (int i = 1;i <= N;i++) {
		fill(visited.begin(), visited.end(), 0);
		int result = bfs(arr, visited, q, i);
		if (result > max) {
			max = result;
			ans.clear();
			ans.push_back(i);
		}
		else if (max == result) {
			ans.push_back(i);
		}
	}

	for (int node : ans) {
		cout << node << ' ';
	}

	return 0;
}