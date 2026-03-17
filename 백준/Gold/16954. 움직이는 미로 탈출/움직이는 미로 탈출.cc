#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

char arr[8][8];
int dy[] = { 0,-1,-1,0,1,1,1,0,-1 };
int dx[] = { 0,0,1,1,1,0,-1,-1,-1 };

void func_move_wall() {
	for (int j = 0; j < 8; j++) {
		for (int i = 7; i > 0; i--) {
			arr[i][j] = arr[i - 1][j];
		}
		arr[0][j] = '.';
	}
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0;i < 8;i++) {
		for (int j = 0;j < 8;j++) {
			cin >> arr[i][j];
		}
	}

	queue<pair<int, int>>q;
	q.push({ 7,0 });
	int turn = 0;
	int ans = 0;
	while (!q.empty()) {
		turn++;
		bool visited[8][8] = { false };
		int L = q.size();
        for (int i = 0; i < L; i++) {
            int y = q.front().first;
            int x = q.front().second;
            q.pop();

            if (arr[y][x] == '#') continue;

            if (y == 0 && x == 7) {
				ans = 1;
				break;
            }

            for (int d = 0; d < 9; d++) {
                int ny = y + dy[d];
                int nx = x + dx[d];

                if (ny < 0 || nx < 0 || ny >= 8 || nx >= 8) continue;
                if (arr[ny][nx] == '#' || visited[ny][nx]) continue;

                visited[ny][nx] = true;
                q.push(make_pair(ny, nx));
            }
        }

        if (turn > 8 && !q.empty()) {
			ans = 1;
			break;
        }
		if (ans == 1) break;
		func_move_wall();

    }

	cout << ans;
	

	return 0;
}