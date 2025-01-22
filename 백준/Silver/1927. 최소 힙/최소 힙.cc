#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	priority_queue<int, vector<int>, greater<int>> pq;

	int N;
	cin >> N;

	for (int i = 0;i < N;i++) {
		int a;
		cin >> a;
		if (a == 0) {
			if (pq.size()) {
				cout << pq.top() << '\n';
				pq.pop();
			}
			else {
				cout << 0 << '\n';
			}
		}
		else {
			pq.push(a);
		}
	}

	return 0;
}