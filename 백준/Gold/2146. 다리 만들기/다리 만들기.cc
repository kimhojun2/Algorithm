#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int N;
int arr[105][105];
int island[105][105];
int distv[105][105];

int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

void island_bfs(queue<pair<int, int> >& edgeq) {
	int id = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (arr[i][j] == 1 && island[i][j] == 0) {
				id++;
				queue<pair<int, int> > q;
				q.push({ i, j });
				island[i][j] = id;

				while (!q.empty()) {
					int y = q.front().first;
					int x = q.front().second;
					q.pop();

					bool edge = false;

					for (int k = 0; k < 4; k++) {
						int ny = y + dy[k];
						int nx = x + dx[k];

						if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;

						if (arr[ny][nx] == 0) edge = true;
						else if (arr[ny][nx] == 1 && island[ny][nx] == 0) {
							island[ny][nx] = id;
							q.push({ ny, nx });
						}
					}

					if (edge) edgeq.push({ y, x });
				}
			}
		}
	}
}

int bridge_bfs(queue<pair<int, int> >& edgeq) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) distv[i][j] = -1;
	}

	queue<pair<int, int> > q;

	while (!edgeq.empty()) {
		int y = edgeq.front().first;
		int x = edgeq.front().second;
		edgeq.pop();

		distv[y][x] = 0;
		q.push({ y, x });
	}

	int ans = 1e9;

	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int k = 0; k < 4; k++) {
			int ny = y + dy[k];
			int nx = x + dx[k];

			if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;

			if (island[ny][nx] == 0) {
				island[ny][nx] = island[y][x];
				distv[ny][nx] = distv[y][x] + 1;
				q.push({ ny, nx });
			}
			else if (island[ny][nx] != island[y][x]) {
				ans = min(ans, distv[ny][nx] + distv[y][x]);
			}
		}
	}

	return ans;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) cin >> arr[i][j];
	}

	queue<pair<int, int> > edgeq;

	island_bfs(edgeq);
	cout << bridge_bfs(edgeq);

	return 0;
}