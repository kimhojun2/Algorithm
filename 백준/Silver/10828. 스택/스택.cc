#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	stack<int>s;
	for (int i = 0;i < N;i++) {
		string order;
		cin >> order;
		if (order == "push") {
			int X;
			cin >> X;
			s.push(X);
		}
		else if (order == "pop") {
			if (s.empty()) {
				cout << -1 << '\n';
			}
			else {
				cout << s.top() << '\n';
				s.pop();
			}
		}
		else if (order =="size") {
			cout << s.size() << '\n';
		}
		else if (order == "empty") {
			if (s.empty()) {
				cout << 1 << '\n';
			}
			else {
				cout << 0 << '\n';
			}
		}
		else {
			if (s.empty()) {
				cout << -1 << '\n';
			}
			else {
				cout << s.top() << '\n';
			}
		}
	}


	return 0;
}