#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, K;

int dp[100001] = { 0, };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N >> K;

	for (int i = 0;i < N;i++) {
		int W, V;
		cin >> W >> V;
		if (W > K) {
			continue;
		}
		for (int j = K;j >= W ;j--) {
			dp[j] = max(dp[j], dp[j - W] + V);
		}
	}
	cout << dp[K];

	return 0;
}