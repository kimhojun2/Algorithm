#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int T;
int dy[8] = {-2,-1,1,2,2,1,-1,-2};
int dx[8] = {1,2,2,1,-1,-2,-2,-1};

int main() {

	int T;
	cin >> T;
	int dy[8] = { -2,-1,1,2,2,1,-1,-2 };
	int dx[8] = { 1,2,2,1,-1,-2,-2,-1 };
	for (int i = 0;i < T;i++) {
		queue<pair<int, int>>q;
		int N;
		cin >> N;
		vector<vector<int>> visited(N, vector<int>(N, 0));
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		q.push({ a,b });
		visited[a][b] = 1;
		
		while (!q.empty()) {
			int y = q.front().first;
			int x = q.front().second;
			q.pop();
			if (y == c && x == d) {
				break;
			}
			for (int d = 0;d < 8;d++) {
				int ny = y + dy[d];
				int nx = x + dx[d];
				if (ny < 0 || nx < 0 || ny >= N || nx >= N) {
					continue;
				}
				if (visited[ny][nx] == 0) {
					visited[ny][nx] = visited[y][x] + 1;
					q.push({ ny,nx });
				}
			}
		}
		cout << visited[c][d] - 1 << '\n';
		
	}

	return 0;
}