#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	int Max_cost = 0;
	vector<int> mem(N + 1), cost(N + 1);
	for (int i = 0;i < N;i++) cin >> mem[i];
	for (int i = 0;i < N;i++) {
		cin >> cost[i];
		Max_cost += cost[i];
	}

	vector<int>dp(Max_cost + 1, 0);
	for (int i = 0;i < N;i++) {
		for (int j = Max_cost;j >= cost[i];j--) {
			dp[j] = max(dp[j], dp[j - cost[i]] + mem[i]);
		}
	}
	for (int j = 0; j <= Max_cost; j++) {
		if (dp[j] >= M) {
			cout << j << '\n';
			break;
		}
	}


	return 0;
}