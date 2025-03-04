#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N, M;
    cin >> N >> M;

    vector<long long> roads(N - 1);
    for (int i = 0; i < N - 1; i++) {
        cin >> roads[i];
    }

    vector<long long> cars(N, 0);
    for (int i = 0; i < M; i++) {
        int u, v, x;
        cin >> u >> v >> x;
        cars[u - 1] += x;
        if (v - 1 < N) {
            cars[v - 1] -= x;
        }
    }

    for (int i = 1; i < N; i++) {
        cars[i] += cars[i - 1];
    }

    for (int i = 0; i < N - 1; i++) {
        long long car = cars[i];
        long long road = roads[i];

        long long quotient = car / road;
        long long remainder = car % road;

        long long result = remainder * (quotient + 1) * (quotient + 1) + (road - remainder) * quotient * quotient;

        cout << result << '\n';
    }

    return 0;
}
