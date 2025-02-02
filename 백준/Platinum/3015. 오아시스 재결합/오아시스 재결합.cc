#include <iostream>
#include <stack>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;
	stack<pair<long,long>> line;
	long long ans = 0;
	for (int i = 0;i < N;i++) {
		long now;
		cin >> now;
		long cnt = 0;
		long equal = 0;

		while (!line.empty()) {
			if (now > line.top().first) {
				cnt += line.top().second + 1;
				line.pop();
			}
			else if (now == line.top().first) {
				cnt += line.top().second + 1;
				equal += line.top().second + 1;
				line.pop();
			}
			else break;
			
		}
		if (!line.empty()) {
			cnt++;
		}
		line.push(make_pair(now, equal));
		ans += cnt;

	}
	cout << ans;

	return 0;
}