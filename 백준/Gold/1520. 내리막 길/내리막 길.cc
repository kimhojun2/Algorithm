#include <iostream>
#include <vector>
using namespace std;

int M, N;
vector<vector<int>> board;
vector<vector<int>> dp;
int dy[4] = { 0, 0, 1, -1 };
int dx[4] = { 1, -1, 0, 0 };

int dfs(int y, int x) {
    if (y == M - 1 && x == N - 1) return 1;
    if (dp[y][x] != -1) return dp[y][x];

    dp[y][x] = 0;
    for (int d = 0; d < 4; d++) {
        int ny = y + dy[d];
        int nx = x + dx[d];
        if (ny >= 0 && ny < M && nx >= 0 && nx < N) {
            if (board[ny][nx] < board[y][x]) {
                dp[y][x] += dfs(ny, nx);
            }
        }
    }
    return dp[y][x];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> M >> N;
    board.assign(M, vector<int>(N));
    dp.assign(M, vector<int>(N, -1));

    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++)
            cin >> board[i][j];

    cout << dfs(0, 0) << '\n';
    return 0;
}
