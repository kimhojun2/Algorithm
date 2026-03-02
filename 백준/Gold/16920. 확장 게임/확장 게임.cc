#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

int N, M, P;
int spd[10];
char arr[1000][1000];

int dy[] = { 0,0,1,-1 };
int dx[] = { 1,-1,0,0 };

queue<pair<int, int>> q[10];
int cnt[10];

void bfs() {
    while (1) {
        bool moved = false;

        for (int i = 1; i <= P; i++) {
            for (int t = 0; t < spd[i]; t++) {
                int qs = (int)q[i].size();
                if (qs == 0) break;

                while (qs--) {
                    int y = q[i].front().first;
                    int x = q[i].front().second;
                    q[i].pop();

                    for (int d = 0; d < 4; d++) {
                        int ny = y + dy[d];
                        int nx = x + dx[d];
                        if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
                        if (arr[ny][nx] != '.') continue;

                        arr[ny][nx] = char('0' + i);
                        q[i].push({ ny,nx });
                        cnt[i]++;
                        moved = true;
                    }
                }
            }
        }

        if (!moved) break;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> P;
    for (int i = 1; i <= P; i++) cin >> spd[i];

    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < M; j++) {
            arr[i][j] = s[j];
            if (arr[i][j] >= '1' && arr[i][j] <= '9') {
                int idx = arr[i][j] - '0';
                q[idx].push({ i,j });
                cnt[idx]++;
            }
        }
    }

    bfs();

    for (int i = 1; i <= P; i++) {
        cout << cnt[i] <<" ";
    }
    return 0;
}