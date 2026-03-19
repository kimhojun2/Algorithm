#include <iostream>
#include <algorithm>
#include <vector>
#include  <queue>
using namespace std;

int N,M;
int arr[20][20];
int temp[20][20];

int dy[] = { 0,0,1,-1 };
int dx[] = { 1,-1,0,0 };

struct Block_group
{
	int size, cnt, y, x;
};
vector<pair<int, int>>delete_arr;

Block_group max_group = { 1,0,0,0 };

int score = 0;

void func_rotate() {
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			temp[N-1-j][i] = arr[i][j];
		}
	}

	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			arr[i][j] = temp[i][j];
		}
	}
}

void func_gravity() {
	for (int j = 0;j < N;j++) {
		int last = N - 1;
		for (int i = N-1;i >= 0;i--) {
			if (arr[i][j] != -2) {
				if (arr[i][j] == -1) {
					last = i - 1;
				}
				else {
					swap(arr[i][j], arr[last][j]);
					last--;
				}
			}
		}
	}
}

void func_make_groups(int sy,int sx, vector<vector<bool>>& done) {
	queue<pair<int, int>>q;
	vector<vector<bool>>visited(N, vector<bool>(N, false));
	q.push({ sy,sx });
	visited[sy][sx] = true;
	int cp = arr[sy][sx];
	Block_group now = { 1,0,sy,sx };
	vector<pair<int, int>>now_delete_arr;
	now_delete_arr.push_back({ sy,sx });

	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int d = 0;d < 4;d++) {
			int ny = y + dy[d];
			int nx = x + dx[d];
			if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
			if (arr[ny][nx] == -1 || visited[ny][nx] || done[ny][nx]) continue;
			//무지개
			if (arr[ny][nx] == 0) {
				now.cnt++;
				now.size++;
				q.push({ ny,nx });
				visited[ny][nx] = true;
				now_delete_arr.push_back({ ny,nx });
			}
			else if (arr[ny][nx] == cp) {
				now.size++;
				q.push({ ny,nx });
				visited[ny][nx] = true;
				done[ny][nx] = true;
				now_delete_arr.push_back({ ny,nx });
			}
		}
	}

	bool change = false;
	if (now.size >= 2) {
		if (max_group.size < now.size) change = true;
		else if (max_group.size == now.size && max_group.cnt < now.cnt) change = true;
		else if (max_group.size == now.size && max_group.cnt == now.cnt && max_group.y <now.y) change = true;
		else if (max_group.size == now.size && max_group.cnt == now.cnt && max_group.y == now.y && max_group.x<now.x) change = true;
	}
	if (change) {
		max_group = now;
		delete_arr = now_delete_arr;
	}
}

void func_point() {
	score += (max_group.size * max_group.size);
	for (pair<int, int> da : delete_arr) {
		arr[da.first][da.second] = -2;
	}
}

void func_reset() {
	delete_arr.clear();
	max_group = { 0,0,0,0 };
}


void func_debug() {
	cout << "--------------------------" << '\n';
	cout << score << '\n';
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			cout << arr[i][j] << " ";
		}cout << '\n';
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			cin >> arr[i][j];
		}
	}

	while (true) {
		func_reset();
		vector<vector<bool>> done(N, vector<bool>(N, false));
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (!done[i][j] && arr[i][j] >= 1) {
					func_make_groups(i, j, done);
				}
			}
		}

		if (max_group.size < 2) break;

		func_point();
		func_gravity();
		func_rotate();
		func_gravity();
	}
	cout << score << endl;


	return 0;
}