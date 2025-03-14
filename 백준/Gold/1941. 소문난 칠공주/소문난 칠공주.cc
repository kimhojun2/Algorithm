#include <iostream>
#include <vector>
#include <queue>
using namespace std;

char arr[5][5];
int dy[] = { 0,0,1,-1 };
int dx[] = { 1,-1,0,0 };
int answer = 0;

bool isConnected(vector<pair<int, int>>& lst) {
    queue<pair<int, int>> q;
    bool visited[5][5] = { false, };

    q.push(lst[0]);
    int check_cnt = 0;

    for (auto& now : lst) {
        visited[now.first][now.second] = true;
    }
    visited[lst[0].first][lst[0].second] = false;
    while (!q.empty()) {
        check_cnt++;
        
        if (check_cnt == 7) return true;
        
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for (int d = 0; d < 4; d++) {
            int ny = y + dy[d];
            int nx = x + dx[d];

            if (ny < 0 || nx < 0 || ny >= 5 || nx >= 5) continue;
            if (!visited[ny][nx]) continue;

            q.push({ ny, nx });
            visited[ny][nx] = false;
        }
    }
    return false;
}

void make(int idx, int level, vector<pair<int, int>>& lst, int S_cnt) {
    if (level == 7) {
         if (S_cnt >= 4 && isConnected(lst)) {
            answer++;
         }
        return;
    }

    for (int i = idx; i < 25; i++) {
        int y = i / 5;
        int x = i % 5;

        lst.push_back({ y, x });

        if (arr[y][x] == 'S') {
            make(i+1, level + 1, lst, S_cnt + 1);
        }
        else {
            make(i+1, level + 1, lst, S_cnt);
        }

        lst.pop_back();
    }
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> arr[i][j];
        }
    }

    vector<pair<int, int>> lst;
    make(0, 0, lst, 0);

    cout << answer;
    return 0;
}
