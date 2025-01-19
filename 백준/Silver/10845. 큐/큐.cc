#include <iostream>
#include <queue>


using namespace std;


int main() {

	int N;
	cin >> N;
	queue<int> q;

	string order;
	int num;
	for (int i = 0;i < N;i++) {
		cin >> order;
		if (order == "push") {
			cin >> num;
			q.push(num);
		}
		else if (order == "pop") {
			if (q.empty()) {
				cout << -1<<'\n';
			}
			else {
				cout << q.front() << '\n';
				q.pop();
			}
		}
		else if (order == "size") {
			cout << q.size() << '\n';
		}
		else if (order == "empty") {
			if (q.empty()) {
				cout << 1 << '\n';
			}
			else {
				cout << 0 << '\n';
			}
		}
		else if (order == "front") {
			if (q.empty()) {
				cout << -1 << '\n';
			}
			else {
				cout << q.front() << '\n';
			}
		}
		else {
			if (q.empty()) {
				cout << -1 << '\n';
			}
			else {
				cout << q.back() << '\n';
			}

		}

	}

	return 0;
}