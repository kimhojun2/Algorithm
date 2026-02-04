#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int R, C, M;

struct Shark {
	int id,y, x, v, dir, size;
	bool alive;
};

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,1,-1 };

vector<Shark>sharks;

int fisherman_pos = -1;
int arr[100][100] = { 0, };
int ans = 0;
int alive_sharks;

void fisherman_turn() {
	for (int i = 0;i < R;i++) {
		int now = arr[i][fisherman_pos];
		if (now != 0 && sharks[now - 1].alive) {
			sharks[arr[i][fisherman_pos] - 1].alive = false;
			arr[i][fisherman_pos] = 0;
			ans += sharks[now-1].size;
			alive_sharks--;
			break;
		}
	}
}

void shark_turn() {
    vector<Shark> new_sharks;

    for (int i = 0; i < M; i++) {
        if (!sharks[i].alive) continue;
        Shark now = sharks[i];

        int k = now.v;

        if (now.dir < 2) {
            if (R > 1) k %= ((R - 1) * 2);
        }
        else {
            if (C > 1) k %= ((C - 1) * 2);
        }

        while (k--) {
            int ny = now.y + dy[now.dir];
            int nx = now.x + dx[now.dir];
            if (ny < 0 || ny >= R || nx < 0 || nx >= C) {
                // 방향 반전
                if (now.dir == 0) now.dir = 1;
                else if (now.dir == 1) now.dir = 0;
                else if (now.dir == 2) now.dir = 3;
                else now.dir = 2;
                // 반전된 방향으로 이동
                now.y += dy[now.dir];
                now.x += dx[now.dir];
            }
            else {
                now.y = ny;
                now.x = nx;
            }
        }
        new_sharks.push_back(now);
    }

    for (int i = 0; i < R; i++) for (int j = 0; j < C; j++) arr[i][j] = 0;

    for (Shark shark : new_sharks) {
        int r = shark.y;
        int c = shark.x;
        if (arr[r][c] == 0) {
            arr[r][c] = shark.id;
            sharks[shark.id - 1] = shark;
        }
        else {
            if (sharks[arr[r][c] - 1].size < shark.size) {
                sharks[arr[r][c] - 1].alive = false;
                arr[r][c] = shark.id;
                sharks[shark.id - 1] = shark;
            }
            else {
                sharks[shark.id - 1].alive = false;
            }
            alive_sharks--;
        }
    }
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> R >> C >> M;
	for (int i = 1;i <= M;i++) {
		int r, c, s, d, z;
		cin >> r >> c >> s >> d >> z;
		sharks.push_back({ i,r - 1,c - 1,s,d-1,z,true });
		arr[r - 1][c - 1] = i;
	}

	alive_sharks = M;

	//for (int i = 0;i < R;i++) {
	//	for (int j = 0;j < C;j++) {
	//		cout << arr[i][j] << " ";
	//	}cout << '\n';
	//}cout << '\n';

    while (fisherman_pos < C - 1 && alive_sharks > 0) {
        fisherman_pos++;
        fisherman_turn();
        shark_turn();
        //for (int i = 0;i < R;i++) {
        //	for (int j = 0;j < C;j++) {
        //		cout << arr[i][j] << " ";
        //	}cout << '\n';
        //}cout << '\n';
    }

	cout << ans;

	return 0;
}