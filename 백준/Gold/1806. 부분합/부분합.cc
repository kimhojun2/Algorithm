#include <iostream>
#include <algorithm>

using namespace std;

int N, S;
int arr[100000];
int ps[100001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> S;

    ps[0] = 0;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        ps[i + 1] = ps[i] + arr[i];
    }

    int left_idx = 0;
    int right_idx = 1;
    int ans = N + 1;

    while (left_idx <= right_idx && right_idx <= N) {
        int s = ps[right_idx] - ps[left_idx];

        if (s >= S) {
            ans = min(ans, right_idx - left_idx);
            left_idx++;
        } else {
            right_idx++;
        }
    }

    if (ans == N + 1) cout << 0;
    else cout << ans;

    return 0;
}
