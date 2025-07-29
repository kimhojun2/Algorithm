#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int M, N, H;
int dz[6] = { 0,0,0,0,1,-1 };
int dy[6] = { 0,0,1,-1,0,0 };
int dx[6] = { 1,-1,0,0,0,0 };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> M >> N >> H;
	vector<vector<vector<int>>> arr(H, vector<vector<int>>(N, vector<int>(M, 0)));
	vector<vector<vector<int>>> visited(H, vector<vector<int>>(N, vector<int>(M, 0)));
	queue<vector<int>> q;

	for (int h = 0; h < H; h++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cin >> arr[h][i][j];
				if (arr[h][i][j] == 1) {
					visited[h][i][j] = 1;
					q.push({ h, i, j });
				}
			}
		}
	}

	while (!q.empty()) {
		int z = q.front()[0];
		int y = q.front()[1];
		int x = q.front()[2];
		q.pop();

		for (int d = 0; d < 6; d++) {
			int nz = z + dz[d];
			int ny = y + dy[d];
			int nx = x + dx[d];

			if (nz < 0 || ny < 0 || nx < 0 || nz >= H || ny >= N || nx >= M) continue;
			if (visited[nz][ny][nx] == 0 && arr[nz][ny][nx] == 0) {
				visited[nz][ny][nx] = visited[z][y][x] + 1;
				q.push({ nz, ny, nx });
			}
		}
	}

	int ans = 0;
	bool bp = false;
	for (int h = 0; h < H; h++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (arr[h][i][j] != -1 && visited[h][i][j] == 0) {
					ans = -1;
					bp = true;
					break;
				}
				ans = max(ans, visited[h][i][j] - 1);
			}
			if (bp) break;
		}
		if (bp) break;
	}

	cout << ans;
	return 0;
}
