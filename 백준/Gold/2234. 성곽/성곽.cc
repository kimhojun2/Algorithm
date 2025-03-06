#include <iostream>
#include <algorithm>
#include <queue>
#include<cstring>
using namespace std;


int N, M;
int visited[51][51];
int arr[51][51];
int cnt = 0;

int dx[4] = { 0, -1, 0, 1 };
int dy[4] = { -1, 0, 1, 0 };


int bfs(int x, int y) {
    cnt++;
    queue<pair<int, int>>q;
    q.push({ x,y });
    visited[x][y] = 1;

    int now_size = 1;
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0;i < 4;i++) {
            if (arr[x][y] & (1 << i)) continue;
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= M || ny >= N) continue;
            if (visited[nx][ny] == 0) {
                visited[nx][ny] = 1;
                q.push({ nx,ny });
                now_size++;
            }
        }
    }

    return now_size;
}



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;

    for (int i = 0;i < M;i++) {
        for (int j = 0;j < N;j++) {
            cin >> arr[i][j];
        }
    }

    int ans1 = 0;
    for (int i = 0;i < M;i++) {
        for (int j = 0;j < N;j++) {
            if (visited[i][j]) continue;
            int now_size = bfs(i, j);
            ans1 = max(ans1, now_size);
        }
    }
    int ans = cnt;
    int ans2 = 0;
    for (int i = 0;i < M;i++) {
        for (int j = 0;j < N;j++) {
            for(int wall = 1; wall <= 8; wall *= 2) {
                if ((arr[i][j] & wall) == wall) {
                    memset(visited, 0, sizeof(visited));
                    arr[i][j] -= wall;
                    int room_size = bfs(i, j);
                    ans2 = max(ans2, room_size);
                    arr[i][j] += wall;
                }
            }
        }
    }


    cout << ans << '\n';
    cout << ans1 << '\n';
    cout << ans2;
    return 0;
}
