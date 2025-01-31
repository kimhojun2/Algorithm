#include <iostream>
#include <queue>

#define MAX_SIZE 501

using namespace std;

int cnt = 0;
int painting_size = 0;
int n = 0, m = 0;
int arr[MAX_SIZE][MAX_SIZE] = { 0, };
int dy[4] = {0,0,1, -1};
int dx[4] = { 1,-1,0,0 };

int bfs(int y, int x) {
	int result = 1;
	arr[y][x] = 0;
	queue<pair<int, int>> q;
	q.push(make_pair(y, x));

	while (!q.empty()) {
		int now_y = q.front().first;
		int now_x = q.front().second;
		q.pop();
		for (int d = 0;d < 4;d++) {
			int ny = now_y + dy[d];
			int nx = now_x + dx[d];
			if (0 > ny || n <= ny || 0 > nx || nx >= m || arr[ny][nx]==0) {
				continue;
			}
			arr[ny][nx] = 0;
			result++;
			q.push(make_pair(ny, nx));
		}
	}
	return result;
}



int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < m;j++) {
			int num;
			cin >> num;
			arr[i][j] = num;
		}
	}
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < m;j++) {
			if (arr[i][j] == 1) {
				int now_size = bfs(i, j);
				cnt++;
				if (now_size > painting_size) {
					painting_size = now_size;
				}
			}
		}
	}
	cout << cnt << '\n' << painting_size;
	return 0;
}