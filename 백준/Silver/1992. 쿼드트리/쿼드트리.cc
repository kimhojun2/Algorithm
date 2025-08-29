#include <iostream>
#include <string>
using namespace std;

int N;
string graph[64];

string ans;


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
        if (graph[y][x] == '0') ans += "0";
        else ans+="1";
        return;
    }
    int h = size / 2;
    ans += "(";
    solve(y, x, h);
    solve(y, x + h, h);
    solve(y + h, x, h);
    solve(y + h, x + h, h);
    ans += ")";
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> graph[i];
    }

    solve(0, 0, N);
    cout << ans;

	return 0;
}