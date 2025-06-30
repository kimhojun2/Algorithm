#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, T;

int graph[100][100] = { 0, };
int visited[100][100][2] = { 0, };

int dy[4] = { 0,0,1,-1 };
int dx[4] = { 1,-1,0,0 };

void bfs() {
	queue<vector<int>>q;
	q.push({ 0,0,0 });
	visited[0][0][0] = 1;

	while (!q.empty()) {
		int y = q.front()[0];
		int x = q.front()[1];
		int k = q.front()[2];

		if (y == N - 1 && x == M - 1) return;

		q.pop();
		for (int d = 0;d < 4;d++) {
			int ny = y + dy[d];
			int nx = x + dx[d];
			
			if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
			
			if (k == 0) {
				if (graph[ny][nx] == 0 && visited[ny][nx][0] == 0) {
					visited[ny][nx][0] = visited[y][x][0] + 1;
					q.push({ ny, nx, 0 });
				}
				else if (graph[ny][nx] == 2 && visited[ny][nx][1] == 0) {
					visited[ny][nx][1] = visited[y][x][0] + 1;
					q.push({ ny, nx, 1 });
				}
			}
			else {
				if (visited[ny][nx][1] == 0) {
					visited[ny][nx][1] = visited[y][x][1] + 1;
					q.push({ ny, nx, 1 });
				}
			}
		}

	}
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M >> T;

	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			cin >> graph[i][j];
		}
	}

	bfs();
	int ans = 1e9;
	if (visited[N - 1][M - 1][0] != 0) ans = visited[N - 1][M - 1][0];
	if (visited[N - 1][M - 1][1] != 0) ans = min(ans, visited[N - 1][M - 1][1]);

	if (ans-1 > T) cout << "Fail";
	else cout << ans-1;

	return 0;
}