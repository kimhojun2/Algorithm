#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

int N;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	vector<int> arr(N);
	for (int i = 0;i < N;i++) {
		cin >> arr[i];
	}

	stack<int>s;
	long long max_area = 0;

	for (int i = 0;i < N;i++) {
		while (!s.empty() && arr[s.top()] > arr[i]) {
			int h = arr[s.top()];
			s.pop();
			int w;
			if(s.empty()) {
				w = i;
			}
			else {
				w = i - s.top()-1;
			}
			long long area = (long long)h * w;
			max_area = max(area, max_area);
		}
		s.push(i);
	}

	while (!s.empty()) {
		int h = arr[s.top()];
		s.pop();
		int w;
		if (s.empty()) {
			w = N;
		}
		else {
			w = N - s.top() - 1;
		}
		long long area = (long long)h * w;
		max_area = max(area, max_area);
	}

	cout << max_area << '\n';

	return 0;
}