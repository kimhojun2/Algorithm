#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int N;
	cin >> N;
	queue<int> q;

	string order;
	int X;
	for (int i = 0;i < N;i++) {
		cin >> order;
		if (order == "push") {
			cin >> X;
			q.push(X);
		}
		else if (order == "pop") {
			if (q.empty()) {
				cout << -1<<'\n';
				continue;
			}
			cout << q.front()<<'\n';
			q.pop();
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
				continue;
			}
			cout << q.front() << '\n';
		}
		else {
			if (q.empty()) {
				cout << -1 << '\n';
				continue;
			}
			cout << q.back() << '\n';
		}

	}



	return 0;
}