#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int N, M;
int start_point, end_point;
vector<pair<int, int>> adj[100001];
bool visited[100001];

bool func_check(long long mid) {
    for (int i = 1; i <= N; i++) {
        visited[i] = false;
    }

    queue<int> q;
    q.push(start_point);
    visited[start_point] = true;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        if (cur == end_point) return true;

        for (int i = 0; i < adj[cur].size(); i++) {
            pair<int, int>& edge = adj[cur][i];
            int next = edge.first;
            int weight_limit = edge.second;

            if (!visited[next] && weight_limit >= mid) {
                visited[next] = true;
                q.push(next);
            }
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    if (!(cin >> N >> M)) return 0;

    long long max_c = 0;
    for (int i = 0; i < M; i++) {
        int A, B, C;
        cin >> A >> B >> C;
        adj[A].push_back(make_pair(B, C));
        adj[B].push_back(make_pair(A, C));
        if (C > max_c) max_c = (long long)C;
    }

    cin >> start_point >> end_point;

    long long low = 1;
    long long high = max_c;
    long long answer = 0;

    while (low <= high) {
        long long mid = low + (high - low) / 2;
        if (func_check(mid)) {
            answer = mid;
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    cout << answer << "\n";

    return 0;
}