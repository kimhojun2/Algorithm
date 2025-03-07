#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int S;
int visited[2001][2001] = { 0 };

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> S;
    queue<pair<int, int>> q;
    q.push({ 1, 0 });
    visited[1][0] = 1;

    while (!q.empty()) {
        int now_screen = q.front().first;
        int now_clip = q.front().second;
        q.pop();

        for (int i = 0; i < 3; i++) {
            int new_screen, new_clip;
            switch (i) {
            case 0:
                new_screen = now_screen;
                new_clip = now_screen;
                break;
            case 1:
                if (now_clip == 0) continue;
                new_screen = now_screen + now_clip;
                new_clip = now_clip;
                break;
            case 2:
                new_screen = now_screen - 1;
                new_clip = now_clip;
                break;
            }

            if (new_screen >= 0 && new_screen <= 2000 && new_clip <= 2000 && visited[new_screen][new_clip] == 0) {
                visited[new_screen][new_clip] = visited[now_screen][now_clip] + 1;
                q.push({ new_screen, new_clip });
            }
        }
    }

    int answer = 1e9;
    for (int i = 0; i <= 2000; i++) {
        if (visited[S][i] != 0) {
            answer = min(answer, visited[S][i]);
        }
    }

    cout << answer - 1 << '\n';
    return 0;
}
