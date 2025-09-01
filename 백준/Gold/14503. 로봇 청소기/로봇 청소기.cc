#include <iostream>
using namespace std;

int N, M;
int init_y, init_x, init_dir;
int room[50][50];
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };
int ans = 0;

void cleaning(int y, int x, int dir) {
    if (room[y][x] == 0) {
        room[y][x] = 2;
        ans++;
    }

    int cur = dir;
    for (int i = 0; i < 4; i++) {
        cur = (cur + 3) % 4;
        int ny = y + dy[cur];
        int nx = x + dx[cur];
        if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
        if (room[ny][nx] == 0) {
            cleaning(ny, nx, cur);
            return;
        }
    }

    int by = y - dy[dir];
    int bx = x - dx[dir];
    if (by < 0 || by >= N || bx < 0 || bx >= M) return;
    if (room[by][bx] == 1) return;
    cleaning(by, bx, dir);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    cin >> init_y >> init_x >> init_dir;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> room[i][j];

    cleaning(init_y, init_x, init_dir);
    cout << ans;
    return 0;
}
