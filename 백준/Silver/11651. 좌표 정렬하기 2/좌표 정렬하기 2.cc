#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool comp(const pair<int,int>& a, const pair<int,int>& b) {
    if (a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    vector<pair<int,int>> v(N);
    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        v[i] = make_pair(x, y);
    }

    sort(v.begin(), v.end(), comp);

    for (int i = 0; i < N; i++) {
        cout << v[i].first << ' ' << v[i].second << '\n';
    }
    return 0;
}
