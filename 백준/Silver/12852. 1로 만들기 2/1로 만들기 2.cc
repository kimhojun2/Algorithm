#include <iostream>
#include <algorithm>

#define MAX_SIZE 1000001
using namespace std;

int N = 0;
int dp[MAX_SIZE] = { 0, };
int nums[MAX_SIZE] = { 0, };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	dp[1] = 0;
	nums[1] = 1;

	for (int i = 2;i <= N;i++) {
		dp[i] = dp[i - 1] + 1;
		nums[i] = i - 1;
		if (i % 2 == 0 && dp[i / 2] + 1 < dp[i]) {
			dp[i] = dp[i / 2] + 1;
			nums[i] = i / 2;
		}
		if (i % 3 == 0 && dp[i / 3] + 1 < dp[i]) {
			dp[i] = dp[i / 3] + 1;
			nums[i] = i / 3;
		}
	}

	cout << dp[N]<<'\n';

	if (N != 0) cout << N << " ";

	while (N != 1) {
		cout << nums[N] << " ";
		N = nums[N];
	}

	return 0;
}