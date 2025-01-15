#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int dx[4] = { -1, 1, 0, 0 };
const int dy[4] = { 0, 0, -1, 1 };

void bfs(vector<string>& grid, vector<vector<bool>>& visited, int x, int y, int& count) {
    int n = grid.size();
    queue<pair<int, int>> q;
    q.push({ x, y });
    visited[x][y] = true;

    while (!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();
        count++;

        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < n && !visited[nx][ny] && grid[nx][ny] == '1') {
                q.push({ nx, ny });
                visited[nx][ny] = true;
            }
        }
    }
}

int main() {
    int n;
    cin >> n;

    vector<string> grid(n);
    vector<vector<bool>> visited(n, vector<bool>(n, false));

    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }

    vector<int> ans;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == '1' && !visited[i][j]) {
                int count = 0;
                bfs(grid, visited, i, j, count);
                ans.push_back(count);
            }
        }
    }


    sort(ans.begin(), ans.end());


    cout << ans.size() << endl;
    for (int size : ans) {
        cout << size << endl;

    }
    
    return 0;
}