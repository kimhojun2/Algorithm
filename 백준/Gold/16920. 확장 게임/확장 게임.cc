#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

int N, M, P;
int dy[4] = { 0, 0, 1, -1 };
int dx[4] = { 1, -1, 0, 0 };
vector<int> S;
vector<string> arr;
vector<queue<pair<int, int>>> q;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> P;
    S.resize(P + 1);
    q.resize(P + 1);

    for (int i = 1; i <= P; i++) cin >> S[i];

    arr.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        for (int j = 0; j < M; j++) {
            if (arr[i][j] >= '1' && arr[i][j] <= '9') {
                int p = arr[i][j] - '0';
                q[p].push(make_pair(i, j));
            }
        }
    }

    while (true) {
        bool moved = false;

        for (int p = 1; p <= P; p++) {
            int speed = S[p];
            queue<pair<int, int>> tmp_q = q[p];
            q[p] = queue<pair<int, int>>();

            for (int s = 0; s < speed && !tmp_q.empty(); s++) {
                int sz = tmp_q.size();
                for (int i = 0; i < sz; i++) {
                    pair<int, int> cur = tmp_q.front();
                    tmp_q.pop();
                    int y = cur.first;
                    int x = cur.second;

                    for (int d = 0; d < 4; d++) {
                        int ny = y + dy[d];
                        int nx = x + dx[d];
                        if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
                        if (arr[ny][nx] != '.') continue;

                        arr[ny][nx] = p + '0';
                        q[p].push(make_pair(ny, nx));
                        tmp_q.push(make_pair(ny, nx));
                        moved = true;
                    }
                }
            }
        }

        if (!moved) break;
    }

    vector<int> result(P + 1, 0);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            if (arr[i][j] >= '1' && arr[i][j] <= '9')
                result[arr[i][j] - '0']++;

    for (int i = 1; i <= P; i++) cout << result[i] << " ";
}
