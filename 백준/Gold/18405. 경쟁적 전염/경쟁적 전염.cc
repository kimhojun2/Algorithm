//우선순위큐 사용X
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct Node {
    int v, t, y, x;
};

int N, K, S, X, Y;
int arr[201][201];

int dy[4] = {0, 0, 1, -1};
int dx[4] = {1, -1, 0, 0};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;

    vector<Node> init;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
            if (arr[i][j] != 0) init.push_back({arr[i][j], 0, i, j});
        }
    }

    cin >> S >> X >> Y;

    sort(init.begin(), init.end(), [](const Node& a, const Node& b) {
        return a.v < b.v;
    });

    queue<Node> q;
    for (auto &n : init) q.push(n);

    while (!q.empty()) {
        Node cur = q.front();
        q.pop();

        if (cur.t == S) break;

        for (int d = 0; d < 4; d++) {
            int ny = cur.y + dy[d];
            int nx = cur.x + dx[d];

            if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
            if (arr[ny][nx] != 0) continue;

            arr[ny][nx] = cur.v;
            q.push({cur.v, cur.t + 1, ny, nx});
        }
    }

    cout << arr[X - 1][Y - 1] << "\n";
    return 0;
}
