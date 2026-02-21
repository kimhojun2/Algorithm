#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int N, M;
int arr[8][8] = { 0, };
int min_area = 64;
int cctv_directions[8];

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };
int rotations[6] = { 0, 4, 2, 4, 4, 1 };

struct Cam {
	int y, x, t;
};

vector<Cam>cctv;

vector<vector<vector<int>>> cctv_shapes = {
	{},                                      
	{{0}, {1}, {2}, {3}},                    
	{{0, 2}, {1, 3}}, 
	{{0, 1}, {1, 2}, {2, 3}, {3, 0}},
	{{0, 1, 2}, {1, 2, 3}, {2, 3, 0}, {3, 0, 1}}, 
	{{0, 1, 2, 3}}                           
};


void check() {
	int temp[8][8];
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			temp[i][j] = arr[i][j];

	for (int i = 0; i < cctv.size(); i++) {
		int type = cctv[i].t;
		int d = cctv_directions[i];
		int y = cctv[i].y;
		int x = cctv[i].x;

		for (int dir : cctv_shapes[type][d]) {
			int ny = y;
			int nx = x;
			while (true) {
				ny += dy[dir];
				nx += dx[dir];

				if (ny < 0 || nx < 0 || ny >= N || nx >= M || temp[ny][nx] == 6) break;
				if (temp[ny][nx] == 0) temp[ny][nx] = -1;
			}
		}
	}

	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (temp[i][j] == 0) cnt++;
		}
	}

	min_area = min(min_area, cnt);
}


void comb(int level) {
	if (level == cctv.size()) {
		check();
		return;
	}

	int type = cctv[level].t;
	for (int d = 0;d < rotations[type];d++) {
		cctv_directions[level] = d;
		comb(level+1);
	}
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			cin >> arr[i][j];
			if (arr[i][j] >= 1 && arr[i][j] <= 5) {
				cctv.push_back({ i,j,arr[i][j] });
			}
		}
	}

	comb(0);

	cout << min_area;

	return 0;
}