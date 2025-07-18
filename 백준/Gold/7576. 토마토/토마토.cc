#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int M, N;
int dy[4] = { 0,0,1,-1 };
int dx[4] = { 1,-1,0,0 };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> M >> N;
	vector<vector<int>>arr(N, vector<int>(M, 0));
	vector<vector<int>>visited(N, vector<int>(M, 0));
	queue<pair<int,int>>q;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 1) {
				visited[i][j] = 1;
				q.push({ i,j });
			}
		}
	}

	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int d = 0;d < 4;d++) {
			int ny = y + dy[d];
			int nx = x + dx[d];
			if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
			if (visited[ny][nx] == 0 && arr[ny][nx] == 0) {
				visited[ny][nx] = visited[y][x] + 1;
				q.push({ ny,nx });
			}
		}
	}
	int ans = 0;
	bool bp = false;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			if (arr[i][j] != -1 and visited[i][j] == 0) {
				ans = -1;
				bp = true;
				break;
			}
			ans = max(ans, visited[i][j]-1);
		}
		if (bp) break;
	}
	cout << ans;
	return 0;
}