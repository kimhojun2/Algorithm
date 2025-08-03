#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> requests;

bool is_possible(int cap) {
    long long total = 0;
    for (int i = 0; i < N; i++) {
        total += min(requests[i], cap);
    }
    return total <= M;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    requests.resize(N);

    for (int i = 0; i < N; i++) {
        cin >> requests[i];
    }

    cin >> M;

    int left = 0;
    int right = *max_element(requests.begin(), requests.end());
    int answer = 0;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (is_possible(mid)) {
            answer = mid;
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    cout << answer << '\n';

    return 0;
}
