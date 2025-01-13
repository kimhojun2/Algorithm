#include <iostream>
#include <set>

using namespace std;

int main() {

	int N, M;
	cin >> N >> M;
	
	set<int>s;
	int num;
	int ans = N + M;
	for (int i = 0;i < N;i++) {
		cin >> num;
		s.insert(num);
	}
	for (int i = 0;i < M;i++) {
		cin >> num;
		if (s.find(num) != s.end()) {
			ans -= 2;
		}
	}

	cout << ans;

	return 0;
}