#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<vector<int>>arr;
vector<int>visited;
vector<int> result_dfs;
vector<int> result_bfs;
queue<int>q;

int N, M, V;


void dfs(int start) {
	visited[start] = 1;
	result_dfs.push_back(start);
	
	for (int i = 0;i < arr[start].size();i++) {
		int next = arr[start][i];
		if (!visited[next]) {
			dfs(next);
		}
	}

}

void bfs(int start) {
	visited[start] = 1;
	q.push(start);
	result_bfs.push_back(start);

	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (int i = 0;i < arr[now].size();i++) {
			int next = arr[now][i];
			if (!visited[next]) {
				visited[next] = 1;
				result_bfs.push_back(next);
				q.push(next);
			}
		}
	}

}


int main() {

	cin >> N >> M >> V;
	arr = vector<vector<int>>(N + 1);

	for (int i = 0;i < M;i++) {
		int s, e;
		cin >> s >> e;

		arr[s].push_back(e);
		arr[e].push_back(s);
	}

	for (int i = 1;i <= N;i++) {
		sort(arr[i].begin(), arr[i].end());
	}

	visited = vector<int>(N + 1, 0);
	dfs(V);
	visited = vector<int>(N + 1, 0);
	bfs(V);



	for (int i = 0; i < result_dfs.size();i++) {
		cout << result_dfs[i] << " ";
	}

	cout << '\n';
	
	for (int i = 0; i < result_bfs.size();i++) {
		cout << result_bfs[i] << " ";
	}

	return 0;
}