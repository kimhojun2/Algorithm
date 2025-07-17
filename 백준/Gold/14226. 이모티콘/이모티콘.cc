#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int S;

void bfs() {
    vector<vector<int>> visited(2001, vector<int>(2001, -1));
    queue<pair<int, int>> q;

    q.push({ 1, 0 }); 
    visited[1][0] = 0;

    while (!q.empty()) {
        int screen = q.front().first;
        int clip = q.front().second;
        q.pop();

        if (screen == S) {
            cout << visited[screen][clip] << '\n';
            return;
        }

        if (visited[screen][screen] == -1) {
            visited[screen][screen] = visited[screen][clip] + 1;
            q.push({ screen, screen });
        }

        if (clip > 0 && screen + clip <= 2000 && visited[screen + clip][clip] == -1) {
            visited[screen + clip][clip] = visited[screen][clip] + 1;
            q.push({ screen + clip, clip });
        }

        if (screen - 1 >= 0 && visited[screen - 1][clip] == -1) {
            visited[screen - 1][clip] = visited[screen][clip] + 1;
            q.push({ screen - 1, clip });
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> S;
    bfs();

    return 0;
}
