#include <iostream>
#include <stack>
#include <queue>

using namespace std;

stack<int>s;
queue<int>q;

int main() {
	int N;
	int idx = 1;
	cin >> N;

	int now;
	string ans = "Nice";
	for (int i = 0;i < N;i++) {
		cin >> now;
		q.push(now);
	}
	while (!q.empty()) {
		if (!s.empty() && s.top() == idx) {
			s.pop();
			idx++;
			continue;
		}
		else if (q.front() == idx) {
			q.pop();
			idx++;
			continue;
		}
		else {
			s.push(q.front());
			q.pop();
		}
	}

	while (!s.empty()) {
		if (s.top() == idx) {
			s.pop();
			idx++;
		}
		else {
			ans = "Sad";
			break;
		}
	}
	cout << ans;

		
	return 0;
}