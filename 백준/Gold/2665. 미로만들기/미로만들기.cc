#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <deque>
using namespace std;

int n;

char arr[50][50];

int dy[] = { 0,0,1,-1 };
int dx[] = { 1,-1,0,0 };

int bfs() {
	deque<pair<int, int>>dq;
	dq.push_back({ 0,0 });
	int visited[50][50] = { 0, };
	visited[0][0] = 1;

	while (!dq.empty()) {
		int y = dq.front().first;
		int x = dq.front().second;
		dq.pop_front();

		if (y == n - 1 && x == n - 1) return visited[y][x] - 1;

		for (int d = 0;d < 4;d++) {
			int ny = y + dy[d];
			int nx = x + dx[d];
			if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
			if (arr[ny][nx] == '1' && (visited[ny][nx] == 0 || visited[ny][nx] > visited[y][x])) {
				visited[ny][nx] = visited[y][x];
				dq.push_front({ ny,nx });
			}
			if (arr[ny][nx] == '0' && (visited[ny][nx] == 0 || visited[ny][nx] > visited[y][x] + 1)) {
				visited[ny][nx] = visited[y][x] + 1;
				dq.push_back({ ny,nx });
			}
		}

	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0;i < n;i++) {
		string now;
		cin >> now;
		for (int j = 0;j < n;j++) {
			arr[i][j] = now[j];
		}
	}

	cout << bfs();

	return 0;
}