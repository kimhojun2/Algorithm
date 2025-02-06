#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N, S;
	cin >> N >> S;
	int arr[100001] = { 0 };
	for (int i = 1;i <= N;i++) {
		int num;
		cin >> num;
		arr[i] = num;
	}
	int start = 1;
	int end = 1;
	int sum = arr[1];
	int ans = INT_MAX;
	while (start <= end && end<=N) {
		if (sum >= S) {
			ans = min(ans, end - start + 1);
		}
		if (sum < S) {
			end++;
			sum += arr[end];
		}
		else {
			sum -= arr[start];
			start++;
		}

	}
	if (ans == INT_MAX) {
		cout << 0 << '\n';
	}
	else {
		cout << ans << '\n';
	}

	return 0;
}