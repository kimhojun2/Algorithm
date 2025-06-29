#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int K, W, H;
int my[4] = { 0,0,1,-1 };
int mx[4] = { 1,-1,0,0 };
int hy[8] = { -2,-1,1,2,2,1,-1,-2 };
int hx[8] = { 1,2,2,1,-1,-2,-2,-1 };

struct monkey
{
	int x;
	int y;
	int k = 0;
};


void bfs(const vector<vector<int>>& graph) {
    vector<vector<vector<int>>> visited(H, vector<vector<int>>(W, vector<int>(K + 1, -1)));
    queue<monkey> q;
    q.push({ 0, 0, 0 });
    visited[0][0][0] = 0;

    while (!q.empty()) {
        monkey now = q.front(); q.pop();

        if (now.y == H - 1 && now.x == W - 1) {
            cout << visited[now.y][now.x][now.k];
            return;
        }

        for (int d = 0; d < 4; d++) {
            int ny = now.y + my[d];
            int nx = now.x + mx[d];
            int nk = now.k;
            if (ny < 0 || nx < 0 || ny >= H || nx >= W) continue;
            if (graph[ny][nx] == 1 || visited[ny][nx][nk] != -1) continue;

            visited[ny][nx][nk] = visited[now.y][now.x][now.k] + 1;
            q.push({ nx, ny, nk });
        }

        if (now.k < K) {
            for (int d = 0; d < 8; d++) {
                int ny = now.y + hy[d];
                int nx = now.x + hx[d];
                int nk = now.k + 1;
                if (ny < 0 || nx < 0 || ny >= H || nx >= W) continue;
                if (graph[ny][nx] == 1 || visited[ny][nx][nk] != -1) continue;

                visited[ny][nx][nk] = visited[now.y][now.x][now.k] + 1;
                q.push({ nx, ny, nk });
            }
        }
    }
    cout << -1 << "\n";
}




int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> K;
	cin >> W >> H;

	vector<vector<int>>graph(H, vector<int>(W,0));

	for (int i = 0;i < H;i++) {
		for (int j = 0;j < W;j++) {
			cin >> graph[i][j];
		}
	}

    bfs(graph);


	return 0;
}