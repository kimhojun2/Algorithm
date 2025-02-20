#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {

	int N;
	cin >> N;
	int answer = 0;
	for (int i = 0;i < N;i++) {
		string str;
		cin >> str;
		stack<char>s;
		for (auto now : str) {
			if (s.empty()) {
				s.push(now);
			}
			else {
				if (s.top() == now) {
					s.pop();
				}
				else{
					s.push(now);
				}
			}
		}
		if (s.empty()) {
			answer++;
		}
	}
	cout << answer;

	return 0;
}