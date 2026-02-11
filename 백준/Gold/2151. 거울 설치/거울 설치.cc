#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int N;
char arr[50][50];
int sy, sx, ey, ex;
bool find_door = false;

int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

struct Node
{
	int y, x, dir;
};

int func_solution() {
	queue<Node>q;
	int visited[50][50][4] = { 0, };
	for (int d = 0;d < 4;d++) {
		q.push({ sy,sx,d });
		visited[sy][sx][d] = 1;
	}
	while (!q.empty()) {
		int y = q.front().y;
		int x = q.front().x;
		int dir = q.front().dir;
		q.pop();

		if (dir == 0 || dir == 1) {
			int ny = y;
			int nx = x;
			while (true) {
				// 쭉 직진하다가
				ny += dy[dir];
				nx += dx[dir];
				//범위 벗어나면 정지
				if (ny < 0 || nx < 0 || ny >= N || nx >= N) break;
				
				if (ny == ey && nx == ex) {
					return visited[y][x][dir]-1;
				}
				// 못가면 정지
				if (arr[ny][nx] == '*') break;
				
				// 거울을 만나면 두가지 경우의 수를 각각 q에 저장하고 계속 직진
				if (arr[ny][nx] == '!' && visited[ny][nx][dir] == 0) {
					q.push({ ny,nx,2 });
					q.push({ ny,nx,3 });
					visited[ny][nx][dir] = visited[y][x][dir];
					visited[ny][nx][2] = visited[y][x][dir] + 1;
					visited[ny][nx][3] = visited[y][x][dir] + 1;
				}
			}
		}
		else {
			int ny = y;
			int nx = x;
			while (true) {
				// 쭉 직진하다가
				ny += dy[dir];
				nx += dx[dir];
				//범위 벗어나면 정지
				if (ny < 0 || nx < 0 || ny >= N || nx >= N) break;

				if (ny == ey && nx == ex) {
					return visited[y][x][dir]-1;
				}
				// 못가면 정지
				if (arr[ny][nx] == '*') break;

				// 거울을 만나면 두가지 경우의 수를 각각 q에 저장하고 계속 직진
				if (arr[ny][nx] == '!' && visited[ny][nx][dir] == 0) {
					q.push({ ny,nx,0 });
					q.push({ ny,nx,1 });
					visited[ny][nx][dir] = visited[y][x][dir];
					visited[ny][nx][0] = visited[y][x][dir] + 1;
					visited[ny][nx][1] = visited[y][x][dir] + 1;
				}
			}
		}
	}
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			cin >> arr[i][j];
			if (arr[i][j] == '#') {
				if (!find_door) {
					sy = i, sx = j;
					find_door = true;
				}
				else ey = i, ex = j;
			}
		}
	}

	cout << func_solution();


	return 0;
}