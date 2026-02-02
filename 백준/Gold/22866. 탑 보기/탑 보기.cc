#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

int N;
int arr[100001];
int ans[100001][2] = { 0, };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	for (int i = 1;i <= N;i++) {
		cin >> arr[i];
	}

	stack<int>s;
	for (int i = 1;i <= N;i++) {
		while (!s.empty() && arr[s.top()] <= arr[i]) {
			s.pop();
		}
		if (!s.empty()) {
			ans[i][0] += s.size();
			ans[i][1] = s.top();
		}

		s.push(i);
	}

	while (!s.empty()) s.pop();

	for (int i = N;i >= 1;i--) {
		while (!s.empty() && arr[s.top()] <= arr[i]) {
			s.pop();
		}
		if (!s.empty()) {
			ans[i][0] += s.size();
			if (ans[i][1] == 0 || abs(i - ans[i][1]) > abs(i - s.top())) {
				ans[i][1] = s.top();
			}
		}

		s.push(i);
	}



	for (int i = 1;i <= N;i++) {
		if (ans[i][0] == 0) cout << 0 << '\n';
		else cout << ans[i][0] << " " << ans[i][1] << '\n';
	}



	return 0;
}