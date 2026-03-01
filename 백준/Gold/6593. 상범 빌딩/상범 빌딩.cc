#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
using namespace std;

int L, R, C;
int sz, sy, sx, ez, ey, ex;
char arr[30][30][30];
int visited[30][30][30] = { 0, };

int dz[] = { 0,0,0,0,1,-1 };
int dy[] = { 1,-1,0,0,0,0 };
int dx[] = { 0,0,1,-1,0,0 };

struct Point {
	int z, y, x;
};

queue<Point>q;

int bfs() {
	q.push({ sz,sy,sx });
	visited[sz][sy][sx] = 1;
	while (!q.empty()) {
		Point now = q.front();
		q.pop();

		if (now.z == ez && now.y == ey && now.x == ex) return visited[ez][ey][ex] - 1;

		for (int d = 0;d < 6;d++) {
			int nz = now.z + dz[d];
			int ny = now.y + dy[d];
			int nx = now.x + dx[d];
			if (nz < 0 || ny < 0 || nx < 0 || nz >= L || ny >= R || nx >= C) continue;
			if (visited[nz][ny][nx] != 0 || arr[nz][ny][nx] == '#') continue;
			visited[nz][ny][nx] = visited[now.z][now.y][now.x] + 1;
			q.push({ nz,ny,nx });
		}
	}

	return -1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	while (true) {
		cin >> L >> R >> C;
		if (L == 0 && R == 0 && C == 0) break;

		while (!q.empty()) q.pop();
		for (int k = 0;k < L;k++) {
			for (int i = 0;i < R;i++) {
				for (int j = 0;j < C;j++) {
					visited[k][i][j] = 0;
				}
			}
		}


		for (int k = 0;k < L;k++) {
			for (int i = 0;i < R;i++) {
				string now;
				cin >> now;
				for (int j = 0;j < C;j++) {
					arr[k][i][j] = now[j];
					if (arr[k][i][j] == 'S') sy = i, sx = j, sz = k;
					else if (arr[k][i][j] == 'E') ey = i, ex = j, ez = k;
				}
			}
		}

		int ans = bfs();
		if (ans != -1) cout << "Escaped in " << ans << " minute(s).\n";
		else cout << "Trapped!\n";
	}


	return 0;
}