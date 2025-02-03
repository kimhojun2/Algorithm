#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, L, R;
int ans = 0;
int dy[4] = { 0, 0, 1, -1 };
int dx[4] = { 1, -1, 0, 0 };
bool BP = true;
queue<pair<int, int>> q;
vector<vector<int>> arr;

void move(vector<vector<int>>& visited) {
    bool moved = false;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (visited[i][j] == 0) {
                visited[i][j] = 1;
                vector<pair<int, int>> lst;
                q.push(make_pair(i, j));
                int cnt_area = 1;
                int sum_area = arr[i][j];
                lst.push_back(make_pair(i, j));


                while (!q.empty()) {
                    int y = q.front().first;
                    int x = q.front().second;
                    q.pop();

                    for (int d = 0; d < 4; d++) {
                        int ny = y + dy[d];
                        int nx = x + dx[d];


                        if (ny < 0 || nx < 0 || ny >= N || nx >= N || visited[ny][nx] == 1) {
                            continue;
                        }


                        if (L <= abs(arr[y][x] - arr[ny][nx]) && abs(arr[y][x] - arr[ny][nx]) <= R) {
                            q.push(make_pair(ny, nx));
                            visited[ny][nx] = 1;
                            cnt_area++;
                            sum_area += arr[ny][nx];
                            lst.push_back(make_pair(ny, nx));
                        }
                    }
                }

                if (cnt_area > 1) {
                    int new_population = sum_area / cnt_area;
                    for (auto& p : lst) {
                        arr[p.first][p.second] = new_population;
                    }
                    moved = true;
                }
            }
        }
    }

    if (moved) {
        BP = true;
        ans++;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> L >> R;
    arr.resize(N, vector<int>(N));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }

    vector<vector<int>> visited(N, vector<int>(N, 0));

    while (BP) {
        BP = false;
        fill(visited.begin(), visited.end(), vector<int>(N, 0));
        move(visited);
    }

    cout << ans;

    return 0;
}
