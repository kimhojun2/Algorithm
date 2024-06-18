#include <iostream>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    int arr[101];

    for (int i = 1; i <= 100; i++) {
        arr[i] = i;
    }

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        int value = arr[a];
        arr[a] = arr[b];
        arr[b] = value;
    }

    for (int j = 1; j <= N; j++) {
        cout << arr[j] << ' ';
    }
    return 0;
}
