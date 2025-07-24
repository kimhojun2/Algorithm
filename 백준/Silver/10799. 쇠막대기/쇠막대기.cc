#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string S;
	cin >> S;

	char before='.';
	int answer = 0;
	int calc = 0;
	for (int i = 0;i < S.size();i++) {
		char now = S[i];
		if (now == '(') {
			calc++;
		}
		else {
			if (before == '(') {
				calc--;
				answer += calc;
			}
			else {
				calc--;
				answer++;
			}
		}
		before = now;

	}

	cout << answer;

	return 0;
}