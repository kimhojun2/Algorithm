#include <iostream>
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N;
	cin >> N;
	vector<pair<int, int>>lectures(N + 1);

	for (int i = 1;i <= N;i++) {
		int idx, s, e;
		cin >> idx >> s >> e;
		lectures[idx] = { s,e };
	}

	sort(lectures.begin(), lectures.end());

	priority_queue<int, vector<int>, greater<>>pq;

	for (int i = 1;i <= N;i++) {
		int start_time = lectures[i].first;
		int end_time = lectures[i].second;

		if (!pq.empty() && pq.top() <= start_time) {
			pq.pop();
		}
		pq.push(end_time);

	}
	
	cout << pq.size();

	return 0;
}