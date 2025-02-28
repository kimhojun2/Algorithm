#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int check(int now, vector<vector<int>>& arr, vector<int>& time, vector<int>& dp) {
    if (dp[now] != -1) return dp[now];

    int value = 0;
    for (int i = 0; i < arr[now].size(); i++) {
        int new_value = check(arr[now][i], arr, time, dp);
        value = max(value, new_value);
    }

    return dp[now] = value + time[now];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);	cout.tie(0);

    int T;
    cin >> T;
    for(int tc=0;tc<T;tc++){
        int N, K;
        cin >> N >> K;

        vector<int> time(N + 1, 0);
        vector<int> dp(N + 1, -1);
        vector<vector<int>> arr(N + 1);

        for (int i = 1; i <= N; i++) {
            cin >> time[i];
        }

        for (int i = 0; i < K; i++) {
            int s, e;
            cin >> s >> e;
            arr[e].push_back(s);
        }

        int start;
        cin >> start;
        cout << check(start, arr, time, dp) << '\n';
    }

    return 0;
}
