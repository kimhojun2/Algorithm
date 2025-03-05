#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int mem[100];
int cost[100];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N, M;
    cin >> N >> M;

    int Max_Cost = 0;
    for (int i = 0; i < N; i++) {
        cin >> mem[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> cost[i];
        Max_Cost += cost[i];
    }

    vector<int> dp(Max_Cost + 1, 0);

    for (int i = 0; i < N; i++) {
        int now_mem = mem[i];
        int now_cost = cost[i];

        for (int j = Max_Cost; j >= now_cost; j--) {
            dp[j] = max(dp[j], dp[j - now_cost] + now_mem);
        }
    }

    for (int j = 0; j <= Max_Cost; j++) {
        if (dp[j] >= M) {
            cout << j << '\n';
            break;
        }
    }

    return 0;
}
