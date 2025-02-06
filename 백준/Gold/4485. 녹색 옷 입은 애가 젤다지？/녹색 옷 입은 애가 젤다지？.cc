#include <iostream>
#include <queue>
#include <algorithm>

#define INF 1e9
using namespace std;

int N;
int arr[125][125] = { 0, };
int di[4] = { 0, 0, 1, -1 };
int dj[4] = { 1, -1, 0, 0 };
int dist[125][125];

void dijkstra() {
    priority_queue<pair<int, pair<int, int>>> pq;
    pq.push({ -arr[0][0], {0, 0} });
    dist[0][0] = arr[0][0];

    while (!pq.empty()) {
        int cost = -pq.top().first;
        int now_y = pq.top().second.first;
        int now_x = pq.top().second.second;
        pq.pop();

        for (int d = 0; d < 4; d++) {
            int next_y = now_y + di[d];
            int next_x = now_x + dj[d];
            if (next_y < 0 || next_x < 0 || next_y >= N || next_x >= N) continue;

            int next_cost = cost + arr[next_y][next_x];
            if (next_cost < dist[next_y][next_x]) {
                dist[next_y][next_x] = next_cost;
                pq.push({ -next_cost, {next_y, next_x} });
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int cnt = 1;

    while (1) {
        cin >> N;
        if (N == 0) break;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cin >> arr[i][j];
            }
        }

        fill(&dist[0][0], &dist[N - 1][N - 1] + 1, INF);

        dijkstra();

        cout << "Problem " << cnt << ": " << dist[N - 1][N - 1] << '\n';
        cnt++;
    }

    return 0;
}
