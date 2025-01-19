#include <iostream>
#include <deque>
using namespace std;

int main() {
	int N;
	cin >> N;

	deque<int> d;
	string order;
	int num;

	for (int i = 0;i < N;i++) {
		cin >> order;
		if (order == "push_front") {
			cin >> num;
			d.push_front(num);
		}
		else if (order == "push_back") {
			cin >> num;
			d.push_back(num);
		}
		else if (order == "pop_front") {
			if (d.empty()) {
				cout << -1 << '\n';
			}
			else {
				cout << d.front() << '\n';
				d.pop_front();
			}
		}
		else if (order == "pop_back") {
			if (d.empty()) {
				cout << -1 << '\n';
			}
			else {
				cout << d.back() << '\n';
				d.pop_back();
			}
		}
		else if (order == "size") {
			cout << d.size() << '\n';
		}
		else if (order == "empty") {
			if (d.empty()) {
				cout << 1 << '\n';
			}
			else {
				cout << 0 << '\n';
			}
		}
		else if (order == "front") {
			if (d.empty()) {
				cout << -1 << '\n';
			}
			else {
				cout << d.front() << '\n';
			}
		}
		else {
			if (d.empty()) {
				cout << -1 << '\n';
			}
			else {
				cout << d.back() << '\n';
			}

		}

	}

	return 0;
}