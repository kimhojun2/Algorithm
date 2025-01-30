#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	vector<vector<int>> dp(n + 1);

	for (int i = 1;i <= n;i++) {
		if (i == 1) {
			int num;
			cin >> num;
			dp[1].push_back(num);
		}
		else {
			for (int now = 0;now < i;now++) {
				int num;
				cin >> num;
				if (now == 0) {
					dp[i].push_back(dp[i-1][0] + num);
				}
				else if (now == i-1) {
					dp[i].push_back(dp[i - 1][i-2] + num);
				}
				else {
					dp[i].push_back(max(dp[i - 1][now - 1], dp[i - 1][now]) + num);
				}
			}
		}
	}

	int ans = -1;
	for (int i = 0;i < dp[n].size();i++) {
		if (dp[n][i] > ans) {
			ans = dp[n][i];
		}
	}
	cout << ans;



	return 0;
}