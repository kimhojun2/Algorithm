#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

int N, M;
int dy[4] = { 0,0,1,-1 };
int dx[4] = { 1,-1,0,0 };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;

	vector<string>graph(N);
	vector<vector<vector<int>>>visited(N, vector<vector<int>>(M, vector<int>(2, 0)));
	
	for (int i = 0;i < N;i++) {
		cin >> graph[i];
	}

	queue<vector<int>>q;
	q.push({ 0,0,0 });
	visited[0][0][0] = 1;
	visited[0][0][1] = 1;

	while (!q.empty()) {
		int y = q.front()[0];
		int x = q.front()[1];
		int wall = q.front()[2];
		q.pop();

		for (int d = 0;d < 4;d++) {
			int ny = y + dy[d];
			int nx = x + dx[d];
			if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
			//	벽이면
			if (graph[ny][nx] == '1') {
				//	벽 부수기 불가능
				if (wall == 1) continue;
				// 벽 부수기 가능
				if (wall == 0) {
					visited[ny][nx][1] = visited[y][x][0] + 1;
					q.push({ ny,nx,1 });
				}

			}
			// 빈 공간이면
			else {
				if (visited[ny][nx][wall] <= visited[y][x][wall] + 1 && visited[ny][nx][wall] != 0) continue;
				visited[ny][nx][wall] = visited[y][x][wall] + 1;
				q.push({ ny,nx,wall });
			}
		}
	}

	int ans;
	if(visited[N - 1][M - 1][0] == 0 && visited[N - 1][M - 1][1]==0) ans = -1;
	else {
		if (visited[N - 1][M - 1][0] == 0 || visited[N - 1][M - 1][1] == 0) ans = max(visited[N - 1][M - 1][0], visited[N - 1][M - 1][1]);
		else ans = min(visited[N - 1][M - 1][0], visited[N - 1][M - 1][1]);
	}
	cout << ans;

	return 0;
}