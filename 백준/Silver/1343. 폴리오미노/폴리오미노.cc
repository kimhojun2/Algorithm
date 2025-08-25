#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string input;
	string ans;
	cin >> input;
	int cnt = 0;
	for (int i = 0;i < input.length();i++) {
		char now = input[i];
		if (now == '.') {
			if (cnt % 2 != 0) {
				cout << -1;
				return 0;
			}
			int A = cnt / 4;
			cnt %= 4;
			for (int j = 0;j < A;j++) {
				ans += "AAAA";
			}
			if (cnt != 0) {
				ans += "BB";
			}
			ans += '.';
			cnt = 0;
		}
		else {
			cnt++;
		}
	}

	if (cnt % 2 != 0) {
		cout << -1;
		return 0;
	}
	int A = cnt / 4;
	cnt %= 4;
	for (int j = 0;j < A;j++) {
		ans += "AAAA";
	}
	if (cnt != 0) {
		ans += "BB";
	}

	cout << ans;

	return 0;
}