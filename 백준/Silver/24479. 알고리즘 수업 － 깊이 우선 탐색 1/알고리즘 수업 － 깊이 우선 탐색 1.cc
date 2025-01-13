#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> list;
vector<int> visited;
int order = 1;

void dfs(int start) {
	visited[start] = order;
	for (int i = 0;i < list[start].size();i++) {
		int next = list[start].at(i);
		if (!visited[next]) {
			order++;
			dfs(next);
		}
	}

}


int main() {
	int N, M, R;
	cin >> N >> M >> R;
	list = vector<vector<int>>(N + 1);
	visited = vector<int>(N + 1, 0);

	for (int i = 0;i < M;i++) {
		int u, v;
		cin >> u >> v;
		list[u].push_back(v);
		list[v].push_back(u);
	}
	for (int i = 0;i <=N;i++) {
		sort(list[i].begin(), list[i].end());
	}

	dfs(R);

	for (int i = 1;i <= N;i++) {
		cout << visited[i] << '\n';
	}

	return 0;
}