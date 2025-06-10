#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	priority_queue<int> Max_pq;   
	priority_queue<int, vector<int>, greater<int>> Min_pq; 

	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;

		if (Max_pq.size() == Min_pq.size()) {
			Max_pq.push(num);
		}
		else {
			Min_pq.push(num);
		}

		if (!Min_pq.empty() && Max_pq.top() > Min_pq.top()) {
			int a = Max_pq.top(); Max_pq.pop();
			int b = Min_pq.top(); Min_pq.pop();
			Max_pq.push(b);
			Min_pq.push(a);
		}

		cout << Max_pq.top() << '\n';
	}

	return 0;
}
