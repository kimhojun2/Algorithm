#include <iostream>

using namespace std;

int N, M;
string A[50];
string B[50];

bool same() {
    for (int i = 0; i < N; i++) {
        if (A[i] != B[i]) return false;
    }

    return true;
}

void flip(int y, int x) {
    for (int i = y; i < y + 3; i++) {
        for (int j = x; j < x + 3; j++) {
            A[i][j] = A[i][j] == '0' ? '1' : '0';
        }
    }
}

void solution() {
    int result = 0;

    for (int i = 0; i < N - 2; i++) {
        for (int j = 0; j < M - 2; j++) {
            if (A[i][j] != B[i][j]) {
                flip(i, j);
                result++;
            }
        }
    }

    if (same()) {
        cout << result;
    }
    else {
        cout << -1;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    for (int i = 0; i < N; i++) {
        cin >> B[i];
    }

    solution();

    return 0;
}