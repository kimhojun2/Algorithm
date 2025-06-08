#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int N, M;
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

            if (ny >= 0 && ny < N && nx >= 0 && nx < M) {
                if (!visited[ny][nx] && graph[ny][nx] > 0) {
                    visited[ny][nx] = true;
                    q.push({ ny, nx });
                }
            }
        }
    }
}


void melting(vector<vector<int>>& graph) {
    vector<vector<int>> temp = graph;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (graph[i][j] > 0) {
                int cnt = 0;
                for (int d = 0; d < 4; d++) {
                    int ny = i + dy[d];
                    int nx = j + dx[d];
                    if (ny >= 0 && ny < N && nx >= 0 && nx < M) {
                        if (temp[ny][nx] == 0) cnt++;
                    }
                }
                graph[i][j] = max(0, graph[i][j] - cnt);
            }
        }
    }
}


int countIcebergs(vector<vector<int>>& graph) {
    vector<vector<bool>> visited(N, vector<bool>(M, false));
    int count = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (graph[i][j] > 0 && !visited[i][j]) {
                bfs(i, j, graph, visited);
                count++;
            }
        }
    }

    return count;
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    vector<vector<int>> graph(N, vector<int>(M));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> graph[i][j];
        }
    }

    int year = 0;

    while (true) {
        int iceberg = countIcebergs(graph);
        if (iceberg >= 2) {
            cout << year << '\n';
            break;
        }
        if (iceberg == 0) {
            cout << 0 << '\n';
            break;
        }

        melting(graph);
        year++;
    }

    return 0;
}