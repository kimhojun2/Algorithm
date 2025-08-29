#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N; cin >> N;
    vector<long long> a(N + 1), psum(N + 1);
    for (int i = 1;i <= N;i++) {
        cin >> a[i];
        psum[i] = psum[i - 1] + a[i];
    }

    long long total = psum[N];
    long long ans = 0;

    // 1) 벌통이 오른쪽 끝
    for (int i = 2;i < N;i++) {
        long long now = total - a[1] - a[i] + (total - psum[i]);
        ans = max(ans, now);
    }

    // 2) 벌통이 왼쪽 끝
    for (int i = 2;i < N;i++) {
        long long now = total - a[N] - a[i] + psum[i - 1];
        ans = max(ans, now);
    }

    // 3) 벌통이 중간
    for (int i = 2;i < N;i++) {
        long long now = psum[i] - a[1] + (total - psum[i - 1] - a[N]);
        ans = max(ans, now);
    }

    cout << ans;
    return 0;
}