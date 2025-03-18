#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
int arr[1000][1000];
int visited[1000][1000];
int dy[] = { 0, 0, 1, -1 };
int dx[] = { 1, -1, 0, 0 };

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;

    int start_y = -1, start_x = -1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
            visited[i][j] = -1;
            if (arr[i][j] == 2) {
                start_y = i;
                start_x = j;
            }
        }
    }

    queue<pair<int, int>> q;
    visited[start_y][start_x] = 0;
    q.push({ start_y, start_x });

    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for (int d = 0; d < 4; d++) {
            int ny = y + dy[d];
            int nx = x + dx[d];

            if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
            if (visited[ny][nx] != -1 || arr[ny][nx] == 0) continue;

            visited[ny][nx] = visited[y][x] + 1;
            q.push({ ny, nx });
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == 0) {
                cout << "0 ";
            }
            else {
                cout << visited[i][j] << " ";
            }
        }
        cout << '\n';
    }

    return 0;
}
