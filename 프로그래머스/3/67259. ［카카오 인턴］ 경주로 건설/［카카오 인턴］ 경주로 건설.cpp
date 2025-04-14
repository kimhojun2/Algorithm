#include <string>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

int dy[] = {-1, 0, 1, 0}; // 상 우 하 좌
int dx[] = {0, 1, 0, -1};

struct Node {
    int y, x, dir, cost;
};

int solution(vector<vector<int>> board) {
    int N = board.size();
    vector<vector<vector<int>>> visited(N, vector<vector<int>>(N, vector<int>(4, INT_MAX)));
    queue<Node> q;

    if (board[0][1] == 0) {
        visited[0][1][1] = 100;
        q.push({0, 1, 1, 100});
    }
    if (board[1][0] == 0) {
        visited[1][0][2] = 100;
        q.push({1, 0, 2, 100});
    }

    while (!q.empty()) {
        Node cur = q.front(); q.pop();

        for (int d = 0; d < 4; d++) {
            int ny = cur.y + dy[d];
            int nx = cur.x + dx[d];

            if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
            if (board[ny][nx] == 1) continue;

            int new_cost = cur.cost + 100;
            if (cur.dir != d) new_cost += 500;

            if (visited[ny][nx][d] > new_cost) {
                visited[ny][nx][d] = new_cost;
                q.push({ny, nx, d, new_cost});
            }
        }
    }

    int answer = INT_MAX;
    for (int d = 0; d < 4; d++) {
        answer = min(answer, visited[N-1][N-1][d]);
    }

    return answer;
}
