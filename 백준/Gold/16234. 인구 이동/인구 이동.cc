#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, L, R;
int arr[50][50];
bool start = true;
int answer = 0;
int dy[] = { 0, 0, 1, -1 };
int dx[] = { 1, -1, 0, 0 };

void check() {
    vector<vector<bool>> visited(N, vector<bool>(N, false));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!visited[i][j]) {
                visited[i][j] = true;

                vector<pair<int, int>> lst;
                lst.push_back({ i, j });

                queue<pair<int, int>> q;
                q.push({ i, j });

                int cnt_area = 1;
                int sum_area = arr[i][j];

                while (!q.empty()) {
                    int y = q.front().first;
                    int x = q.front().second;
                    q.pop();

                    for (int d = 0; d < 4; d++) {
                        int ny = y + dy[d];
                        int nx = x + dx[d];

                        if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
                        if (visited[ny][nx]) continue;

                        int next = arr[ny][nx];

                        if (L <= abs(arr[y][x] - next) && abs(arr[y][x] - next) <= R) {
                            q.push({ ny, nx });
                            visited[ny][nx] = true;
                            cnt_area++;
                            sum_area += next;
                            lst.push_back({ ny, nx });
                        }
                    }
                }

                if (cnt_area > 1) {
                    int change = sum_area / cnt_area;
                    for (auto& com : lst) {
                        arr[com.first][com.second] = change;
                    }
                    start = true;
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> L >> R;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }

    while (start) {
        start = false;
        check();
        if (start) answer++;
    }

    cout << answer;
    return 0;
}
