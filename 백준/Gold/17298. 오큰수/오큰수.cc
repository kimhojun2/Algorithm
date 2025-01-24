#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	stack<pair<int, int>>s;
	vector<int> ans(N, -1);

	for (int i = 0;i < N;i++) {
		int num;
		cin >> num;
		while (!s.empty() && s.top().second < num) {
			ans[s.top().first] = num;
			s.pop();
		}
		s.push(make_pair(i, num));
	}
	for (int i : ans) {
		cout << i << ' ';
	}

	return 0;
}