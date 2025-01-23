#include <iostream>
#include <stack>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	stack<pair<int, int>> s;
	for (int i = 1;i <= N;i++) {
		int height;
		cin >> height;
		while (!s.empty()) {
			if (height < s.top().second) {
				cout << s.top().first << ' ';
				break;
			}
			s.pop();
		}
		if (s.empty()) {
			cout << 0 << ' ';
		}
		s.push(make_pair(i, height));
	}

	return 0;
}