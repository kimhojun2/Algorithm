#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int N, M, F;
int arr[21][21];
int dy[] = { -1,0,0,1 };
int dx[] = { 0,-1,1,0 };

int sy, sx;
vector<pair<int, int>>people;
vector<pair<int, int>>stop;


int func_find() {
    // [1단계] 가장 가까운 승객 찾기
    int min_dist = 1e9;
    int pos_y = -1, pos_x = -1;

    queue<pair<int, int>> q;
    vector<vector<int>> visited(N, vector<int>(N, 0));

    // 택시 현재 위치에 승객이 있는 경우 바로 처리
    if (arr[sy][sx] > 1) {
        pos_y = sy; pos_x = sx;
        min_dist = 1;
    }
    else {
        q.push({ sy, sx });
        visited[sy][sx] = 1;

        while (!q.empty()) {
            int y = q.front().first;
            int x = q.front().second;
            q.pop();

            // 이미 찾은 최단 거리보다 멀어지면 탐색 중단
            if (min_dist != 1e9 && visited[y][x] >= min_dist) break;

            for (int d = 0; d < 4; d++) {
                int ny = y + dy[d], nx = x + dx[d];
                if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
                if (arr[ny][nx] == 1 || visited[ny][nx]) continue;

                visited[ny][nx] = visited[y][x] + 1;

                if (arr[ny][nx] > 1) { // 승객 발견!
                    if (visited[ny][nx] < min_dist) {
                        min_dist = visited[ny][nx];
                        pos_y = ny; pos_x = nx;
                    }
                    else if (visited[ny][nx] == min_dist) {
                        // 거리 같으면 '행'이 작은 순, 같다면 '열'이 작은 순
                        if (ny < pos_y || (ny == pos_y && nx < pos_x)) {
                            pos_y = ny; pos_x = nx;
                        }
                    }
                }
                q.push({ ny, nx });
            }
        }
    }

    // 승객을 못 찾았거나, 가는 도중 연료가 바닥난 경우 (거리 1당 연료 1)
    if (pos_y == -1 || (min_dist - 1) > F) return -1;

    // 승객 태우기: 연료 차감 및 승객 정보 저장
    F -= (min_dist - 1);
    int passenger_idx = arr[pos_y][pos_x];
    arr[pos_y][pos_x] = 0; // 지도에서 승객 제거
    sy = pos_y; sx = pos_x; // 택시를 승객 위치로 이동

    // [2단계] 목적지로 이동하기
    while (!q.empty()) q.pop(); // 큐 초기화
    for (int i = 0; i < N; i++) fill(visited[i].begin(), visited[i].end(), 0); // visited 초기화

    q.push({ sy, sx });
    visited[sy][sx] = 1;

    int target_y = stop[passenger_idx - 2].first;
    int target_x = stop[passenger_idx - 2].second;
    bool reached = false;

    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        if (y == target_y && x == target_x) {
            reached = true;
            break;
        }

        for (int d = 0; d < 4; d++) {
            int ny = y + dy[d], nx = x + dx[d];
            if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
            if (arr[ny][nx] == 1 || visited[ny][nx]) continue;

            visited[ny][nx] = visited[y][x] + 1;
            q.push({ ny, nx });
        }
    }

    int go_dist = visited[target_y][target_x] - 1;
    // 목적지에 못 가거나, 가는 도중 연료 바닥 (딱 0이 되는 건 성공)
    if (!reached || go_dist > F) return -1;

    // 목적지 도착: 연료 충전 및 택시 위치 갱신
    F += go_dist;
    sy = target_y; sx = target_x;

    return F;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M >> F;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			cin >> arr[i][j];
		}
	}

	int y, x;
	cin >> y >> x;
	sy = y - 1;
	sx = x - 1;

	for (int i = 2;i <= M+1;i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		arr[a-1][b-1] = i;
		people.push_back({ a-1,b-1 });
		stop.push_back({ c-1,d-1 });
	}

    bool possible = true;
    for (int i = 0; i < M; i++) {
        int result = func_find();

        if (result == -1) {
            possible = false;
            break;
        }
    }

 
    if (possible) {
        cout << F << endl;
    }
    else {
        cout << -1 << endl;
    }

	return 0;
}