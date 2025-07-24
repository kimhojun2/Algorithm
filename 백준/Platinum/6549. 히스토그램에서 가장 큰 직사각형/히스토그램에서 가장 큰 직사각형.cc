#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	while (1) {
		int N;
		cin >> N;
		if (N == 0) break;

		vector<int> arr(N);
		for (int i = 0; i < N; i++) {
			cin >> arr[i];
		}

		stack<int> s;
		long long max_area = 0; 

		for (int i = 0; i < N; i++) {
			while (!s.empty() && arr[s.top()] > arr[i]) {
				int height = arr[s.top()];
				s.pop();
				int width;
				if (s.empty()) {
					width = i;
				}
				else {
					width = i - s.top() - 1;
				}
				long long area = (long long)height * width;
				if (area > max_area) max_area = area;
			}
			s.push(i);
		}

		while (!s.empty()) {
			int height = arr[s.top()];
			s.pop();
			int width;
			if (s.empty()) {
				width = N;
			}
			else {
				width = N - s.top() - 1;
			}
			long long area = (long long)height * width;
			if (area > max_area) max_area = area;
		}

		cout << max_area << '\n';
	}

	return 0;
}
