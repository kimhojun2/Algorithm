#include <iostream>
#include <algorithm>
using namespace std;

int dp[1001][3] = { 0, };
int N;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	for (int i = 1;i <= N;i++) {
		int red, green, blue;
		cin >> red >> green >> blue;
		if (i == 1) {
			dp[1][0] = red;
			dp[1][1] = green;
			dp[1][2] = blue;
		}
		else {
			dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + red;
			dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + green;
			dp[i][2] = min(dp[i-1][0],dp[i-1][1]) + blue;
		}
	}

	cout << min(min(dp[N][0], dp[N][1]), dp[N][2]);


	return 0;
}