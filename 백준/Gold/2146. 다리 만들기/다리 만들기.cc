#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N;
int dy[4] = { 0, 0, 1, -1 };
int dx[4] = { 1, -1, 0, 0 };

void island_indexing(vector<vector<int>>& arr, vector<vector<int>>& visited, int sy, int sx, int idx) {
	queue<pair<int, int>> q;
	q.push({ sy, sx });
	visited[sy][sx] = 1;
	arr[sy][sx] = idx;

	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int d = 0; d < 4; d++) {
			int ny = y + dy[d];
			int nx = x + dx[d];
			if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
			if (!visited[ny][nx] && arr[ny][nx] == 1) {
				visited[ny][nx] = 1;
				arr[ny][nx] = idx;
				q.push({ ny, nx });
			}
		}
	}
}

int find_min_bridge_from_island(vector<vector<int>>& arr, int island_id) {
	vector<vector<int>> dist(N, vector<int>(N, -1));
	queue<pair<int, int>> q;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (arr[i][j] == island_id) {
				for (int d = 0; d < 4; d++) {
					int ni = i + dy[d];
					int nj = j + dx[d];
					if (ni < 0 || nj < 0 || ni >= N || nj >= N) continue;
					if (arr[ni][nj] == 0) {
						q.push({ i, j });
						dist[i][j] = 0;
						break;
					}
				}
			}
		}
	}

	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int d = 0; d < 4; d++) {
			int ny = y + dy[d];
			int nx = x + dx[d];
			if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
			if (arr[ny][nx] != 0 && arr[ny][nx] != island_id) {
				return dist[y][x];
			}
			if (arr[ny][nx] == 0 && dist[ny][nx] == -1) {
				dist[ny][nx] = dist[y][x] + 1;
				q.push({ ny, nx });
			}
		}
	}

	return 1e9;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	vector<vector<int>> arr(N, vector<int>(N));
	vector<vector<int>> visited(N, vector<int>(N, 0));

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> arr[i][j];

	int idx = 2;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (arr[i][j] == 1 && visited[i][j] == 0)
				island_indexing(arr, visited, i, j, idx++);

	int answer = 1e9;
	for (int k = 2; k < idx; k++)
		answer = min(answer, find_min_bridge_from_island(arr, k));

	cout << answer << '\n';
	return 0;
}
