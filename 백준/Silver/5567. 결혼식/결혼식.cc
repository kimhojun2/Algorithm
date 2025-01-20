#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;

int bfs(vector<vector<int>>& arr) {
    vector<int> visited(n + 1, 0);
    queue<pair<int, int>> q;
    q.push({1, 0});
    visited[1] = 1;
    int count = 0;

    while (!q.empty()) {
        int now = q.front().first;
        int depth = q.front().second;
        q.pop();

        if (depth >= 2) continue;

        for (int i = 0; i < arr[now].size(); i++) {
            int next = arr[now][i];
            if (!visited[next]) {
                visited[next] = 1;
                count++;
                q.push({next, depth + 1});
            }
        }
    }

    return count;
}

int main() {
    cin >> n >> m;
    vector<vector<int>> arr(n + 1);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }

    int result = bfs(arr);
    cout << result;

    return 0;
}
