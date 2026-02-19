#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

int N;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	stack<pair<int, int>>s;

	for (int i = 1;i <= N;i++) {
		int a;
		cin >> a;
		if (s.empty()) {
			cout << 0<<" ";
		}
		else {
			while (!s.empty() && s.top().first < a) {
				s.pop();
			}
			if (s.empty())cout << 0 << " ";
			else cout << s.top().second << " ";
		}
		s.push({ a,i });
	}


	return 0;
}