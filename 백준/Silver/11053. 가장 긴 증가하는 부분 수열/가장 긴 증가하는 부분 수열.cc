#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int V, E;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N;
	cin >> N;
	vector<int>arr(N, 0);
	vector<int>dp(N, 1);
	int max_value = 1;
	for (int i = 0;i < N;i++) {
		cin >> arr[i];
		for (int j = 0;j < i;j++) {
			if (arr[j] < arr[i] && dp[j]+1 > dp[i]) {
				dp[i] = dp[j] + 1;
			}
		}
		if (dp[i] > max_value) max_value = dp[i];
	}

	cout << max_value;

	return 0;
}