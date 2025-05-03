#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

int N, M;
int sy, sx, ey, ex;
int dy[4] = { 0, 0, 1, -1 };
int dx[4] = { 1, -1, 0, 0 };

int bfs(vector<vector<char>>& graph) {
    vector<vector<int>> visited(N, vector<int>(M, 0));
    queue<pair<int, int>> water_q;
    queue<pair<int, int>> hedgehog_q;


    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            if (graph[i][j] == '*')
                water_q.push({ i, j });
    hedgehog_q.push({ sy, sx });
    visited[sy][sx] = 1;

    while (!hedgehog_q.empty()) {
        int water_size = water_q.size();
        for (int i = 0; i < water_size; i++) {
            int y = water_q.front().first;
            int x = water_q.front().second;
            water_q.pop();
            for (int d = 0; d < 4; d++) {
                int ny = y + dy[d];
                int nx = x + dx[d];
                if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
                if (graph[ny][nx] == '.' || graph[ny][nx] == 'S') {
                    graph[ny][nx] = '*';
                    water_q.push({ ny, nx });
                }
            }
        }


        int hedgehog_size = hedgehog_q.size();
        for (int i = 0; i < hedgehog_size; i++) {
            int y = hedgehog_q.front().first;
            int x = hedgehog_q.front().second;
            hedgehog_q.pop();
            for (int d = 0; d < 4; d++) {
                int ny = y + dy[d];
                int nx = x + dx[d];
                if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
                if (graph[ny][nx] == 'D') return visited[y][x];
                if (graph[ny][nx] == '.' && visited[ny][nx] == 0) {
                    visited[ny][nx] = visited[y][x] + 1;
                    hedgehog_q.push({ ny, nx });
                }
            }
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    vector<vector<char>> graph(N, vector<char>(M));
    for (int i = 0; i < N; i++) {
        string line;
        cin >> line;
        for (int j = 0; j < M; j++) {
            graph[i][j] = line[j];
            if (line[j] == 'S') {
                sy = i;
                sx = j;
            }
        }
    }

    int answer = bfs(graph);
    if (answer == -1)
        cout << "KAKTUS";
    else
        cout << answer;

    return 0;
}
