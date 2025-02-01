#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	priority_queue<int, vector<int>> pq;
	for (int i = 0;i < n;i++) {
		int idx;
		cin >> idx;
		if (idx == 0) {
			if (pq.empty()) {
				cout << -1<<'\n';
			}
			else {
				cout << pq.top()<<'\n';
				pq.pop();
			}
		}
		else {
			for (int j = 0;j < idx;j++) {
				int value;
				cin >> value;
				pq.push(value);
			}
		}
	}


	return 0;
}