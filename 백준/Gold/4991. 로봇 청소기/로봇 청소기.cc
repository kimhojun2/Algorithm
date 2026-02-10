#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int w, h;
char arr[20][20];
int dy[] = { 0,0,1,-1 };
int dx[] = { 1,-1,0,0 };

vector<pair<int, int>>dirty_rooms;
int sy, sx;

struct Node {
	int y, x, dirty;
};

void func_reset() {
	dirty_rooms.clear();
	for (int i = 0;i < h;i++) {
		for (int j = 0;j < w;j++) {
			arr[i][j] = '.';
		}
	}
}


int func_solution() {
	int cnt = (1 << dirty_rooms.size());
	vector<vector<vector<int>>>visited(h, vector<vector<int>>(w, vector<int>(cnt, 0)));
	queue<Node>q;
	q.push({ sy,sx,0 });
	visited[sy][sx][0] = 0;
	arr[sy][sx] = '.';

	while (!q.empty()) {
		int y = q.front().y;
		int x = q.front().x;
		int dirty = q.front().dirty;
		q.pop();

		if (dirty == cnt - 1) {
			return visited[y][x][dirty];
		}

		for (int d = 0;d < 4;d++) {
			int ny = y + dy[d];
			int nx = x + dx[d];
			int next_dirty = dirty;
			if (ny < 0 || nx < 0 || ny >= h || nx >= w) continue;	//	전체 범위 넘어서면 이동 불가능
			if (arr[ny][nx] == 'x') continue;	//	가구칸이면 이동 불가능
			if (visited[ny][nx][dirty]) continue;	// 같은 상태로 이전에 방문했으면 이동 불가능
			
			//	더러운 칸이면
			if (arr[ny][nx] == '*') {
				int check;
				for (int i = 0;i < dirty_rooms.size();i++) {
					if (dirty_rooms[i].first == ny && dirty_rooms[i].second == nx) {
						check = i;
						break;
					}
				}
				//새로운 루틴이라면
				if (!(dirty & (1 << check))) {
					next_dirty += (1 << check);
				}
			}
			visited[ny][nx][next_dirty] = visited[y][x][dirty] + 1;
			q.push({ ny,nx,next_dirty });
		}

	}

	return -1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	while (true) {
		cin >> w >> h;
		if (w == 0 && h == 0) break;
		func_reset();

		for (int i = 0;i < h;i++) {
			for (int j = 0;j < w;j++) {
				cin >> arr[i][j];
				if (arr[i][j] == 'o') {
					sy = i, sx = j;
				}
				else if (arr[i][j] == '*') {
					dirty_rooms.push_back({ i,j });
				}
			}
		}
		if (dirty_rooms.size() == 0) continue;
		cout << func_solution()<<'\n';
	}

	return 0;
}