#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>>arr;
vector<int>visited;
int order = 1;


void dfs(int start) {
	visited[start] = order;

	for (int i = 0;i < arr[start].size();i++) {
		int next = arr[start].at(i);
		if (!visited[next]) {
			order++;
			dfs(next);
		}
	}
}


int main() {

	int N, M, R;
	cin >> N >> M >> R;
	arr = vector<vector<int>>(N + 1);
	visited = vector<int>(N + 1, 0);

	for (int i = 0;i < M;i++) {
		int s, e;
		cin >> s >> e;
		arr[s].push_back(e);
		arr[e].push_back(s);
	}

	for (int i = 1;i <= N;i++) {
		sort(arr[i].begin(), arr[i].end(), greater<int>());
	}

	dfs(R);

	for (int i = 1;i <= N;i++) {
		cout << visited[i] << '\n';
	}

	return 0;
}