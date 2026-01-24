#include <iostream>
#include <queue>

#define MAXSIZE 1001

using namespace std;

int M, N, area;

int dy[4] = { 0,0,1,-1 };
int dx[4] = { 1,-1,0,0 };

int arr[MAXSIZE][MAXSIZE];
int visited[MAXSIZE][MAXSIZE];
queue<pair<int,int>>q;


int bfs() {
	int L;
	int days = 0;
	while (!q.empty()) {
		L = q.size();
		for (int i = 0;i < L;i++) {
			int y = q.front().first;
			int x = q.front().second;
			q.pop();
			for (int d = 0;d < 4;d++) {
				int ny = y + dy[d];
				int nx = x + dx[d];
				if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
				if (visited[ny][nx] || arr[ny][nx] != 0) continue;

				arr[ny][nx] = 1;
				visited[ny][nx] = 1;
				area--;
				q.push({ ny,nx });

			}
		}
		days++;
	}

	if (area == 0) return days-1;
	return -1;

}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> M >> N;
	area = N * M;

	int n;

	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			cin >> n;

			arr[i][j] = n;
			if (n == 0) continue;
			if (n == 1) q.push({ i,j });
			area--;
		}
	}

	cout << bfs();


	return 0;
}