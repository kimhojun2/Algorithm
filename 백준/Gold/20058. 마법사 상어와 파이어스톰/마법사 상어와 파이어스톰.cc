#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int N, Q;
int arr[64][64];
int temp[64][64];

int dy[] = { 0,0,1,-1 };
int dx[] = { 1,-1,0,0 };

void func_rotate(int sy, int sx, int size) {
	for (int i = 0;i < size;i++) {
		for (int j = 0;j < size;j++) {
			temp[j][size - 1 - i] = arr[sy + i][sx + j];
		}
	}
	for (int i = 0;i < size;i++) {
		for (int j = 0;j < size;j++) {
			arr[sy + i][sx + j] = temp[i][j];
		}
	}
}

bool func_melt(int y, int x, int M) {
	int cnt = 0;
	for (int d = 0;d < 4;d++) {
		int ny = y + dy[d];
		int nx = x + dx[d];
		if (ny < 0 || nx < 0 || ny >= M || nx >= M)continue;
		if (arr[ny][nx] != 0) cnt++;
	}

	if (cnt >= 3) return false;
	
	return true;
}

pair<int,int> func_chek(int M) {
	vector<vector<bool>>visted(M, vector<bool>(M, false));
	queue<pair<int, int>>q;

	int cnt = 0;
	int max_ice = 0;
	for (int i = 0;i < M;i++) {
		for (int j = 0;j < M;j++) {
			cnt += arr[i][j];
			if (!visted[i][j] && arr[i][j]>0) {
				q.push({ i,j });
				visted[i][j] = true;
				int now_cnt = 1;
				while (!q.empty()) {
					int y = q.front().first;
					int x = q.front().second;
					q.pop();
					for (int d = 0;d < 4;d++) {
						int ny = y + dy[d];
						int nx = x + dx[d];
						if (ny < 0 || nx < 0 || ny >= M || nx >= M) continue;
						if (arr[ny][nx] != 0 && !visted[ny][nx]) {
							now_cnt++;
							visted[ny][nx] = true;
							q.push({ ny,nx });
						}
					}
				}
				max_ice = max(max_ice, now_cnt);
			}
		}
	}

	return { cnt,max_ice };
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> Q;
	int M = (1<<N);
	for (int i = 0;i < M;i++) {
		for (int j = 0;j < M;j++) {
			cin >> arr[i][j];
		}
	}

	for (int t = 0;t < Q;t++) {
		int q;
		cin >> q;
		int target_size = (1 << q);

		for (int i = 0;i < M;i+=target_size) {
			for (int j = 0;j < M;j += target_size) {
				func_rotate(i, j, target_size);
			}
		}
		vector<pair<int, int>>lst;
		for (int i = 0;i < M;i++) {
			for (int j = 0;j < M;j++) {
				if (arr[i][j] != 0) {
					if (func_melt(i, j, M)) {
						lst.push_back({ i,j });
					}
				}
			}
		}
		for (pair<int, int> now : lst) {
			arr[now.first][now.second]--;
		}

	}

	cout << func_chek(M).first << '\n' << func_chek(M).second;


	return 0;
}