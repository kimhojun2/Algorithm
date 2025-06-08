#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int N;
int dy[4] = { 0, 0, 1, -1 };
int dx[4] = { 1, -1, 0, 0 };

void bfs(int y, int x, vector<vector<int>>& graph, vector<vector<bool>>& visited) {
    queue<pair<int, int>> q;
    q.push({ y, x });
    visited[y][x] = true;

    while (!q.empty()) {
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();

        for (int dir = 0; dir < 4; dir++) {
            int ny = cy + dy[dir];
            int nx = cx + dx[dir];

            if (ny >= 0 && ny < N && nx >= 0 && nx < N) {
                if (!visited[ny][nx] && graph[ny][nx] != 0) {
                    visited[ny][nx] = true;
                    q.push({ ny, nx });
                }
            }
        }
    }
}

int rain(vector<vector<int>> graph, int now) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (graph[i][j] <= now) {
                graph[i][j] = 0;
            }
        }
    }

    int cnt = 0;
    vector<vector<bool>> visited(N, vector<bool>(N, false));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (graph[i][j] != 0 && !visited[i][j]) {
                bfs(i, j, graph, visited);
                cnt++;
            }
        }
    }

    return cnt;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    vector<vector<int>> graph(N, vector<int>(N));
    int maxHeight = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> graph[i][j];
            maxHeight = max(maxHeight, graph[i][j]);
        }
    }

    int maxSafe = 1;
    for (int h = 1; h <= maxHeight; h++) {
        int result = rain(graph, h);
        maxSafe = max(maxSafe, result);
    }

    cout << maxSafe;
    return 0;
}
