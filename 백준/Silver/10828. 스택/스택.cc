#include <iostream>
#include <stack>
using namespace std;

int main() {
	ios::sync_with_stdio;
	cin.tie(NULL);

	int N;
	cin >> N;

	stack<int>s;

	for (int i = 0;i < N;i++) {
		string order;
		cin >> order;
		if (order == "push") {
			int a;
			cin >> a;
			s.push(a);
		}
		else if (order == "pop") {
			if (s.size()) {
				cout << s.top() << '\n';
				s.pop();
			}
			else {
				cout << -1 << '\n';
			}
		}
		else if (order == "size") {
			cout << s.size() << '\n';
		}
		else if (order == "empty") {
			if (s.size()) {
				cout << 0 << '\n';
			}
			else {
				cout << 1 << '\n';
			}
		}
		else {
			if (s.size()) {
				cout << s.top() << '\n';
			}
			else {
				cout << -1 << '\n';
			}
		}

	}

	return 0;
}