#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>>arr;
vector<int>visited;

void dfs(int start) {
	visited[start] = 1;
	for (int i = 0;i < arr[start].size();i++) {
		int next = arr[start].at(i);
		if (!visited[next]) {
			dfs(next);
		}
	}
}




int main() {
	int N, M;
	cin >> N >> M;

	arr = vector<vector<int>>(N + 1);
	visited = vector<int>(N + 1, 0);

	for (int i = 0;i < M;i++) {
		int s, e;
		cin >> s >> e;
		arr[s].push_back(e);
		arr[e].push_back(s);
	}
	int ans = 0;
	for (int i = 1;i <= N;i++) {
		if (!visited[i]) {
			dfs(i);
			ans++;
		}
	}
	cout << ans;

	return 0;
}