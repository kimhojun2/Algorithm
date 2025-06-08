#include <iostream>
#include <vector>
using namespace std;

int N, K;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> K;

	vector<vector<int>>graph(N, vector<int>(N, 0));

	int now = N * N;
	int dir = 0;
	int y = 0;
	int x = 0;
	int dy[4] = { 1,0,-1,0 };
	int dx[4] = { 0,1,0,-1 };

	pair<int, int>ans = { 0,0 };

	for (int i = 0;i < N * N;i++) {
		graph[y][x] = now;
		if (now == K) {
			ans.first = y+1;
			ans.second = x+1;
		}
		if (y + dy[dir] < 0 || y + dy[dir] >= N || x + dx[dir] < 0 || x + dx[dir] >= N || graph[y+dy[dir]][x+dx[dir]] != 0) {
			dir = (dir + 1) % 4;
		}
		y += dy[dir];
		x += dx[dir];
		now--;
	}

	for (int i = 0;i < N;i++) {
		for (int j = 0; j < N;j++) {
			cout << graph[i][j] << " ";
		}cout << '\n';
	}
	cout << ans.first << " " << ans.second;


	return 0;
}