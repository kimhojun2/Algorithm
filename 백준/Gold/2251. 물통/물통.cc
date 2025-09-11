#include <iostream>
using namespace std;

int A, B, C;
bool visited[201][201][201];
bool possible[201];

void dfs(int a, int b, int c) {
    if (visited[a][b][c]) return;
    visited[a][b][c] = true;
    if (a == 0) possible[c] = true;

    int na, nb, nc;

    nb = min(b + a, B);
    na = a - (nb - b);
    dfs(na, nb, c);

    nc = min(c + a, C);
    na = a - (nc - c);
    dfs(na, b, nc);

    na = min(a + b, A);
    nb = b - (na - a);
    dfs(na, nb, c);

    nc = min(c + b, C);
    nb = b - (nc - c);
    dfs(a, nb, nc);

    na = min(a + c, A);
    nc = c - (na - a);
    dfs(na, b, nc);

    nb = min(b + c, B);
    nc = c - (nb - b);
    dfs(a, nb, nc);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> A >> B >> C;
    dfs(0, 0, C);

    for (int i = 0; i <= 200; i++) {
        if (possible[i]) cout << i << ' ';
    }
    return 0;
}
