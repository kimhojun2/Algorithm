#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	stack<pair<int,int>>s;
	vector<int> ans(N + 1, 0);
	
	for (int i = 1;i <= N;i++) {
		int height;
		cin >> height;
		while (!s.empty() && s.top().second <= height) {
			ans[s.top().first] = i - s.top().first - 1;
			s.pop();
		}
		s.push(make_pair(i, height));
	}

	while (!s.empty()) {
		ans[s.top().first] = N - s.top().first;
		s.pop();
	}

	long long sum = 0;
	for (int i = 1;i <= N;i++) {
		sum += ans[i];
	}
	cout << sum;

	return 0;
}