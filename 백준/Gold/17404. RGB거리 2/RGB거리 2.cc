#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int N;
	cin >> N;
	vector<vector<int>>dp(N, vector<int>(3, 0));
	vector<vector<int>>arr(N, vector<int>(3, 0));
	
	for (int i = 0;i < N;i++) {
		int a, b, c;
		cin >> a >> b >> c;
		arr[i] = { a,b,c };
	}
	int answer = 1000001;
	for (int color = 0; color < 3;color++) {

		for (int l = 0;l < 3;l++) {
			if (l == color) {
				dp[0][l] = arr[0][l];
			}
			else {
				dp[0][l] = 987654321;
			}
		}

		for (int i = 1; i < N;i++) {
			dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + arr[i][0];
			dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + arr[i][1];
			dp[i][2] = min(dp[i - 1][1], dp[i - 1][0]) + arr[i][2];
		}
		for (int l = 0;l < 3;l++) {
			if (l == color) {
				continue;
			}
			answer = min(answer, dp[N - 1][l]);
		}
		//check
		//cout << '\n';
		//for (int i = 0; i < N;i++) {
		//	for (int j = 0; j < 3;j++) {
		//		cout << dp[i][j] << " ";
		//	}
		//	cout << '\n';
		//}
	}
	cout << answer;

	return 0;
}