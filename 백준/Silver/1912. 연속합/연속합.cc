#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	std::cin.tie(nullptr)->sync_with_stdio(false);

	int n;
	std::cin >> n;

	std::vector<int> v(n);
	for (int i = 0; i < n; ++i)
		std::cin >> v[i];

	std::vector<int> dp(n, 0);

	int max = v[0];
	dp[0] = v[0];

	for (int i = 1; i < n; ++i) {
		dp[i] = std::max(dp[i - 1] + v[i], v[i]);
		max = std::max(dp[i], max);
	}
	std::cout << max << '\n';
}

