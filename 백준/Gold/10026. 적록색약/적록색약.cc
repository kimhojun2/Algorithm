#include <iostream>
#include <queue>
#include <string>
using namespace std;

int N;
char board[100][100];

bool visited_normal[100][100];
bool visited_abnormal[100][100];

int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

void bfs(int sy, int sx, bool visited[100][100], bool is_abnormal) {
    queue<pair<int, int>> q;
    q.push({ sy, sx });
    visited[sy][sx] = true;
    char color = board[sy][sx];

    while (!q.empty()) {
        int y = q.front().first; 
        int x = q.front().second;
        q.pop();

        for (int d = 0; d < 4; d++) {
            int ny = y + dy[d];
            int nx = x + dx[d];

            if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue;
            if (visited[ny][nx]) continue;

            char next = board[ny][nx];

            if (is_abnormal) {
                if ((color == 'R' || color == 'G') && (next == 'R' || next == 'G')) {
                    visited[ny][nx] = true;
                    q.push({ ny, nx });
                }
                else if (color == next) {
                    visited[ny][nx] = true;
                    q.push({ ny, nx });
                }
            }
            else {
                if (next == color) {
                    visited[ny][nx] = true;
                    q.push({ ny, nx });
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        string s; cin >> s;
        for (int j = 0; j < N; j++) {
            board[i][j] = s[j];
        }
    }

    int normal = 0, abnormal = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!visited_normal[i][j]) {
                bfs(i, j, visited_normal, false);
                normal++;
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!visited_abnormal[i][j]) {
                bfs(i, j, visited_abnormal, true);
                abnormal++;
            }
        }
    }

    cout << normal << ' ' << abnormal << '\n';

    return 0;
}
