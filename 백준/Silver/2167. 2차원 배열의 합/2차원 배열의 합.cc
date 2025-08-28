#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, M, K;
	cin >> N >> M;

	vector<vector<int>>prefix_sum(N, vector<int>(M));

	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			int now;
			cin >> now;
			prefix_sum[i][j] = now;
			if (i) prefix_sum[i][j] += prefix_sum[i - 1][j];
			if (j) prefix_sum[i][j] += prefix_sum[i][j - 1];
			if (i && j)prefix_sum[i][j] -= prefix_sum[i - 1][j - 1];
		}
	}

	

	cin >> K;
	for (int k = 0;k < K;k++) {
		int i, j, x, y;
		cin >> i >> j >> x >> y;
		int ans = prefix_sum[x - 1][y - 1];
		if (i > 1) ans -= prefix_sum[i - 2][y - 1];
		if (j > 1) ans -= prefix_sum[x - 1][j - 2];
		if (i > 1 && j > 1) ans += prefix_sum[i - 2][j - 2];
		cout << ans << '\n';
	}



	return 0;
}