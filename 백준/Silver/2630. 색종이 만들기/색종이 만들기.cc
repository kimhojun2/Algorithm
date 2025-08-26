#include <iostream>
using namespace std;

int blue = 0;
int white = 0;
int graph[128][128];

bool same(int y, int x, int size) {
    int v = graph[y][x];
    for (int i = y; i < y + size; i++) {
        for (int j = x; j < x + size; j++) {
            if (graph[i][j] != v) return false;
        }
    }
    return true;
}

void solve(int y, int x, int size) {
    if (same(y, x, size)) {
        if (graph[y][x] == 0) white++;
        else blue++;
        return;
    }
    int h = size / 2;
    solve(y, x, h);
    solve(y, x + h, h);
    solve(y + h, x, h);
    solve(y + h, x + h, h);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> graph[i][j];
        }
    }

    solve(0, 0, N);
    cout << white << '\n' << blue << '\n';
    return 0;
}
