#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, M;
vector<pair<int, int>> virus;
vector<int> selected;
vector<vector<int>> arr_origin;
int min_time = 1e9;
int dy[4] = { 0,0,1,-1 };
int dx[4] = { 1,-1,0,0 };

void bfs() {
	vector<vector<int>> arr = arr_origin;
	vector<vector<int>> visited(N, vector<int>(N, -1));
	queue<pair<int, int>> q;

	for (int i = 0; i < M; i++) {
		int y = virus[selected[i]].first;
		int x = virus[selected[i]].second;
		q.push({ y, x });
		visited[y][x] = 0;
	}

	int time = 0;

	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int d = 0; d < 4; d++) {
			int ny = y + dy[d];
			int nx = x + dx[d];

			if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
			if (arr[ny][nx] != 1 && visited[ny][nx] == -1) {
				visited[ny][nx] = visited[y][x] + 1;
				q.push({ ny, nx });
			}
		}
	}

	bool all_spread = true;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (arr[i][j] == 0) {
				if (visited[i][j] == -1) {
					all_spread = false;
				}
				else {
					time = max(time, visited[i][j]);
				}
			}
		}
	}


	if (all_spread) {
		min_time = min(min_time, time);
	}
}

void comb(int idx, int cnt) {
	if (cnt == M) {
		bfs();
		return;
	}

	for (int i = idx; i < virus.size(); i++) {
		selected.push_back(i);
		comb(i + 1, cnt + 1);
		selected.pop_back();
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;

	vector<vector<int>> arr(N, vector<int>(N));
	int empty = 0;

	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 2) {
				virus.push_back({ i,j });
			}
			if (arr[i][j] == 0) {
				empty++;
			}
		}
	}

	if (empty == 0) {
		cout << 0 << '\n';
		return 0;
	}

	arr_origin = arr;
	comb(0, 0);

	if (min_time == 1e9) cout << -1 << '\n';
	else cout << min_time << '\n';

	return 0;
}
