#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int C, N;
int dp[1101] = { 0, };
const int INF = 1e9;

vector<pair<int, int>>lst;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> C >> N;
	for (int i = 0;i < N;i++) {
		int v, e;
		cin >> v >> e;
		lst.push_back({ v,e });
	}

	fill(dp, dp + 1101, INF);
	dp[0] = 0;

	for (int i = 1;i <= C + 100;i++) {
		for (pair<int, int> curr : lst) {
			int cost = curr.first;
			int cnt = curr.second;

			if (i >= cnt) {
				if (dp[i - cnt] != INF) {
					dp[i] = min(dp[i], dp[i - cnt] + cost);
				}
			}
		}
	}

	int ans = INF;
	for (int i = C; i <= C + 100; i++) {
		ans = min(ans, dp[i]);
	}

	cout << ans;

	return 0;
}