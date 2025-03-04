#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, res = 0;
vector<pair<int, int>> arr;
int dp[100];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		arr.push_back({ a,b });
	}

	sort(arr.begin(), arr.end());

	for (int i = 0; i < n; i++) {
		dp[i] = 1;
		for (int j = 0; j < i; j++) {
			if (arr[j].second < arr[i].second) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}

		res = max(res, dp[i]);
	}

	cout << n - res;

	return 0;
}