#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N, M;
string arr[101];
int visited[101][101] = { 0, };
int dy[4] = { 0,0,1,-1 };
int dx[4] = { 1,-1,0,0 };

void bfs() {
	queue<pair<int, int>> q;
	q.push({ 0,0 });
	visited[0][0] = 1;

	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();


		for (int i = 0;i < 4;i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || nx < 0 || ny >= N || nx >= M || arr[ny][nx] == '0') {
				continue;
			}
			if (visited[ny][nx] == 0) {
				visited[ny][nx] = visited[y][x] + 1;
				q.push({ ny,nx });
			}
		}


	}
	

}


int main() {

	cin >> N >> M;

	for (int i = 0;i < N;i++) {
		cin >> arr[i];
	}

	bfs();

	if (visited[N - 1][M - 1] > 0) {
		cout << visited[N - 1][M - 1];
	}
	else {
		cout << -1;
	}

	return 0;
}