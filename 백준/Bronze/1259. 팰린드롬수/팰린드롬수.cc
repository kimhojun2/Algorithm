#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	string check="";
	
	while (1) {
		string answer = "yes";
		cin >> check;
		stack<char>s;
		if (check == "0") break;

		for (int i = 0; i <= check.length() / 2;i++) {
			if (check[i] != check[check.length() - 1 - i]) {
				answer = "no";
			}
		}
		cout << answer << '\n';
	}
	return 0;
}