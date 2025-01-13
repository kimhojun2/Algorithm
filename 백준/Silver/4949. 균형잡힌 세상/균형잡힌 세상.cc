#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {

	string str;
	while (true) {
		stack<char>s;
		string ans = "yes";
		getline(cin, str);
		if (str == ".") {
			break;
		}
		for (char c : str) {
			if (c == '[' || c == '(') {
				s.push(c);
			}
			else if(c == ']') {
				if (s.empty() || s.top() != '[') {
					ans = "no";
					break;
				}
				s.pop();
			}
			else if (c == ')') {
				if (s.empty() || s.top() != '(') {
					ans = "no";
					break;
				}
				s.pop();
			}
		}
		if (!s.empty()) {
			ans = "no";
		}

		cout << ans << '\n';
	}

	return 0;
}