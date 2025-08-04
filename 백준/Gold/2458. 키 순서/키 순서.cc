#include <iostream>
#include <vector>
#include <queue>
#include <cstring> // for memset
using namespace std;

int N, M;
vector<vector<int>> taller, smaller;

int bfs(int start, const vector<vector<int>>& graph) {
    queue<int> q;
    vector<bool> visited(N + 1, false);
    q.push(start);
    visited[start] = true;

    int cnt = 0;
    while (!q.empty()) {
        int now = q.front(); q.pop();
        for (int next : graph[now]) {
            if (!visited[next]) {
                visited[next] = true;
                q.push(next);
                cnt++;
            }
        }
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    taller = vector<vector<int>>(N + 1);
    smaller = vector<vector<int>>(N + 1);

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        taller[a].push_back(b);
        smaller[b].push_back(a);
    }

    int answer = 0;

    for (int i = 1; i <= N; i++) {
        int high = bfs(i, taller);
        int low = bfs(i, smaller);
        if (high + low == N - 1) answer++;
    }

    cout << answer << '\n';
    return 0;
}
