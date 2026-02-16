#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    vector<int> a(N);
    for (int i = 0; i < N; i++) cin >> a[i];
    sort(a.begin(), a.end());

    int M;
    cin >> M;
    for (int i = 0; i < M; i++) {
        int x;
        cin >> x;
        int l = lower_bound(a.begin(), a.end(), x) - a.begin();
        int r = upper_bound(a.begin(), a.end(), x) - a.begin();
        cout << (r - l);
        if (i + 1 < M) cout << ' ';
    }
    cout << '\n';
    return 0;
}
