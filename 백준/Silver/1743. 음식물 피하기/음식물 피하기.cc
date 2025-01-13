#include <iostream>
#include <vector>
using namespace std;

int N, M, K;
vector<vector<int>> arr;
vector<vector<int>> visited;

int dy[4] = {0, 0, 1, -1};
int dx[4] = {1, -1, 0, 0};
int area = 0;
int M_area = 0;

void dfs(int y, int x) {
    visited[y][x] = 1;
    area++;

    for (int d = 0; d < 4; d++) {
        int ny = y + dy[d], nx = x + dx[d];
        if (ny < 0 || nx < 0 || ny >= N || nx >= M) {
            continue;
        }
        if (!visited[ny][nx] && arr[ny][nx] == 1) {
            dfs(ny, nx);
        }
    }
}

int main() {
    cin >> N >> M >> K;

    arr = vector<vector<int>>(N, vector<int>(M, 0));
    visited = vector<vector<int>>(N, vector<int>(M, 0));

    for (int i = 0; i < K; i++) {
        int r, c;
        cin >> r >> c;
        arr[r - 1][c - 1] = 1;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (!visited[i][j] && arr[i][j] == 1) {
                area = 0;
                dfs(i, j);
                M_area = max(M_area, area);
            }
        }
    }

    cout << M_area << endl;

    return 0;
}
