#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;
	priority_queue<int, vector<int>> pq;

	int one;
	cin >> one;

	if (N == 1) {
		cout << 0;
		return 0;
	}

	for (int i = 0;i < N - 1;i++) {
		int vote;
		cin >> vote;
		pq.push(vote);
	}
	int cnt = 0;
	while (pq.top() >= one) {
		int now = pq.top();
		now--;
		cnt++;
		one++;
		pq.pop();
		pq.push(now);

	}
	cout << cnt;

	return 0;
}