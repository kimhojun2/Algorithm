#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int arr[201] = { 0, };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	for (int i = 0;i < N;i++) {
		cin >> arr[i];
	}
	vector<int>dp(N, 1);
	for (int i = 1;i < N;i++) {
		for (int j = 0;j < i;j++) {
			if (arr[j] < arr[i] && dp[i] < dp[j]+1) {
				dp[i] = dp[j] + 1;
			}
		}
	}

	int max_value = dp[0];
	for (int i = 1;i < N;i++) {
		max_value = max(max_value, dp[i]);
	}

	cout << N - max_value;

	return 0;
}