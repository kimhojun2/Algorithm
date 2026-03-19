#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int R, C, T;
int arr[50][50] = { 0, };
int temp[50][50] = { 0, };
int up = -1;
int down = -1;

int dy[] = { 0,-1,0,1 };
int dx[] = { 1,0,-1,0 };

void spread() {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (arr[i][j] != 0 && arr[i][j] != -1) {
				int new_dust = arr[i][j] / 5;
				int now_dust = arr[i][j];

				for (int d = 0; d < 4; d++) {
					int ny = i + dy[d];
					int nx = j + dx[d];

					if (ny < 0 || nx < 0 || ny >= R || nx >= C) continue;
					if (arr[ny][nx] == -1) continue;

					now_dust -= new_dust;
					temp[ny][nx] += new_dust;
				}
				temp[i][j] += now_dust;
			}
		}
	}
	temp[up][0] = -1;
	temp[down][0] = -1;
}

void move() {
	int up_now = 0;
	int down_now = 0;

	for (int j = 1; j < C; j++) {
		int up_temp = temp[up][j];
		temp[up][j] = up_now;
		up_now = up_temp;
	}
	for (int i = up - 1; i >= 0; i--) {
		int up_temp = temp[i][C - 1];
		temp[i][C - 1] = up_now;
		up_now = up_temp;
	}
	for (int j = C - 2; j >= 0; j--) {
		int up_temp = temp[0][j];
		temp[0][j] = up_now;
		up_now = up_temp;
	}
	for (int i = 1; i < up; i++) {
		int up_temp = temp[i][0];
		temp[i][0] = up_now;
		up_now = up_temp;
	}

	for (int j = 1; j < C; j++) {
		int down_temp = temp[down][j];
		temp[down][j] = down_now;
		down_now = down_temp;
	}
	for (int i = down + 1; i < R; i++) {
		int down_temp = temp[i][C - 1];
		temp[i][C - 1] = down_now;
		down_now = down_temp;
	}
	for (int j = C - 2; j >= 0; j--) {
		int down_temp = temp[R - 1][j];
		temp[R - 1][j] = down_now;
		down_now = down_temp;
	}
	for (int i = R - 2; i > down; i--) {
		int down_temp = temp[i][0];
		temp[i][0] = down_now;
		down_now = down_temp;
	}

	temp[up][0] = -1;
	temp[down][0] = -1;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			arr[i][j] = temp[i][j];
			temp[i][j] = 0;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> R >> C >> T;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == -1) {
				if (up == -1) up = i;
				else down = i;
			}
		}
	}

	while (T--) {
		spread();
		move();
	}

	int ans = 0;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (arr[i][j] > 0) ans += arr[i][j];
		}
	}

	cout << ans;

	return 0;
}