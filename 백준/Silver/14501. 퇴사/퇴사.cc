#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;
	int dp[17] = { 0, };
	int arr[17][2] = { 0, };

	for (int i = 1;i <= N;i++) {
		cin >> arr[i][0] >> arr[i][1];
	}
	
	for (int i = N;i >= 1;i--) {
		if (i + arr[i][0] > N+1) {
			dp[i] = dp[i + 1];
		}
		else {
			dp[i] = max(dp[i + 1], dp[i + arr[i][0]] + arr[i][1]);
		}
	}

	cout << dp[1];

	return 0;
}