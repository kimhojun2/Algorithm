#include <iostream>
#include <algorithm>
using namespace std;

int n;
int arr[500][500];
int dp[500][500];

int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };

int dfs(int y, int x) {
    if (dp[y][x] != 0) return dp[y][x];

    dp[y][x] = 1;

    for (int d = 0; d < 4; d++) {
        int ny = y + dy[d];
        int nx = x + dx[d];
        if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
        if (arr[ny][nx] <= arr[y][x]) continue; 

        dp[y][x] = max(dp[y][x], dfs(ny, nx) + 1);
    }

    return dp[y][x];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];

    int ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            ans = max(ans, dfs(i, j));

    cout << ans;
    return 0;
}
