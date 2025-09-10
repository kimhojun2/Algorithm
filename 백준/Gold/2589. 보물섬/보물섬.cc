#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;

int N, M;
string graph[50];
int ans = 0;
int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };


void bfs(int y, int x) {
	queue<pair<int, int>>q;
	q.push({ y,x });
	vector<vector<int>>visited(N, vector<int>(M, 0));
	visited[y][x] = 1;
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int d = 0;d < 4;d++) {
			int ny = y + dy[d];
			int nx = x + dx[d];
			if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
			if (graph[ny][nx] == 'W' || visited[ny][nx] != 0) continue;
			visited[ny][nx] = visited[y][x] + 1;
			if (visited[ny][nx] - 1 > ans) ans = visited[ny][nx] - 1;
			q.push({ ny,nx });
		}

	}
}



int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 0;i < N;i++) {
		cin >> graph[i];
	}

	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			if (graph[i][j] == 'L') {
				bfs(i, j);
			}
		}
	}

	cout << ans;

	return 0;
}