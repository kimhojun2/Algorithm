#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	priority_queue<int, vector<int>> heap;
	int N;
	cin >> N;

	for (int i = 0;i < N;i++) {
		int a;
		cin >> a;
		if (a == 0) {
			if (heap.empty()) {
				cout << 0 << '\n';
				continue;
			}
			cout << heap.top() << '\n';
			heap.pop();
		}
		else {
			heap.push(a);
		}
	}

	return 0;
}