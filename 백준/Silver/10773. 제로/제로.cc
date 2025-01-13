#include <iostream>
#include <stack>

using namespace std;

int main() {
	int K;
	cin >> K;

	stack<int>s;

	int num;
	int total = 0;
	for (int i = 0;i < K;i++) {
		cin >> num;
		if (num == 0) {
			if (!s.empty()) {
				total -= s.top();
				s.pop();
				
			}
		}
		else {
			s.push(num);
			total += num;
		}
	}

	cout << total;

	return 0;
}