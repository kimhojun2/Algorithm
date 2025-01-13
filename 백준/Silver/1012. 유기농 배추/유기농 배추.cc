#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>>arr;
vector<vector<int>>visited;

int M, N, K;
int dy[4] = { 1,-1,0,0 };
int dx[4] = { 0,0,1,-1 };

void dfs(int y ,int x) {
	visited[y][x] = 1;
	for (int d = 0;d < 4;d++) {
		int ny = y + dy[d];
		int nx = x + dx[d];
		if (ny < 0 || ny >= N || nx < 0 || nx >= M) {
			continue;
		}
		if (arr[ny][nx] && !visited[ny][nx]) {
			dfs(ny, nx);
		}
	}
}


int main() {
	int T;
	cin >> T;
	for (int tc = 0;tc < T;tc++) {
		cin >> M >> N >> K;

		arr = vector<vector<int>>(N,vector<int>(M,0));
		visited = vector<vector<int>>(N, vector<int>(M,0));


		for (int i = 0;i < K;i++) {
			int X, Y;
			cin >> X >> Y;
			arr[Y][X] = 1;
		}

		int ans = 0;
		for (int i = 0;i < N;i++) {
			for (int j = 0;j < M;j++) {
				if (arr[i][j] && !visited[i][j]) {
					dfs(i, j);
					ans++;
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}