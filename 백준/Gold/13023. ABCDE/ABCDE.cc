#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<vector<int>> graph;

bool backtracking(int u, int depth, vector<int>& visited) {
    if (depth == 4) return true;
    for (int i = 0; i < graph[u].size(); i++) {
        int v = graph[u][i];
        if (visited[v]) continue;
        visited[v] = 1;
        if (backtracking(v, depth + 1, visited)) return true;
        visited[v] = 0;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    graph.assign(N, vector<int>());
    for (int i = 0; i < M; i++) {
        int A, B;
        cin >> A >> B;
        graph[A].push_back(B);
        graph[B].push_back(A);
    }

    for (int i = 0; i < N; i++) {
        vector<int> visited(N, 0);
        visited[i] = 1;
        if (backtracking(i, 0, visited)) {
            cout << 1;
            return 0;
        }
    }
    cout << 0;
    return 0;
}
