#include <iostream>
#include <vector>

#define DEV 1000000000
using namespace std;



int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N;
	cin >> N;
	vector<vector<int>> dp(N, vector<int>(10, 0));
	dp[0] = { 0,1,1,1,1,1,1,1,1,1 };

	for (int i = 1;i < N;i++) {
		for (int j = 0;j < 10;j++) {
			if (j == 0) {
				dp[i][0] = dp[i - 1][1]% DEV;
			}
			else if (j == 9) {
				dp[i][9] = dp[i - 1][8]% DEV;
			}
			else {
				dp[i][j] = (dp[i-1][j - 1] + dp[i-1][j + 1]) % DEV;
			}
		}
	}


	//for (int i= 0;i < N;i++) {
	//	for (int j = 0;j < 10;j++) {
	//		cout << dp[i][j] << " ";
	//	}cout << '\n';
	//}
	int answer = 0;
	for (int j = 0; j < 10; j++) {
		answer = (answer + dp[N - 1][j]) % DEV;
	}
	cout << answer % DEV;

	return 0;
}