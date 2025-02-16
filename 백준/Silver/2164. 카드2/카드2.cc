#include <iostream>
#include <deque>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	deque<int> dq;
	int N;
	cin >> N;
	for (int i = N;i >= 1;i--) {
		dq.push_back(i);
	}
	while (dq.size() > 1) {
		dq.pop_back();
		int now = dq.back();
		dq.pop_back();
		dq.push_front(now);
	}
	cout << dq[0];

	return 0;
}