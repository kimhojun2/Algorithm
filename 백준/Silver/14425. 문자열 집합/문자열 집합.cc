#include <iostream>
#include <map>

using namespace std;

int main() {	
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	map <string, bool>m;
	string str;

	for (int i = 0;i < N;i++) {
		cin >> str;
		m[str] = true;
	}
	int cnt = 0;
	for (int i = 0;i < M;i++) {
		cin >> str;
		if (m.find(str) != m.end()) {
			cnt++;
		}
	}
	cout << cnt;

	return 0;
}