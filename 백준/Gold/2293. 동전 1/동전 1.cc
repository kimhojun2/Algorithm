#include <iostream>
#include <vector>
using namespace std;

int n, k;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	vector<int>coins(n);
	for (int i = 0;i < n;i++) {
		cin >> coins[i];
	}

	vector<int>dp(k + 1, 0);
	dp[0] = 1;

	for (int coin : coins) {
		for (int i = coin;i < k+1;i++) {
			dp[i] += dp[i - coin];
		}
	}

	cout << dp[k];



	return 0;
}