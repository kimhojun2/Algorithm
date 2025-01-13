#include <iostream>
#include <set>
using namespace std;

int main() {

	string S;
	cin >> S;
	set <string>s;
	int cnt = 0;

	string str = "";
	for (int i = 0;i < S.size();i++) {
		for (int j = i;j < S.size();j++) {
			str += S[j];
			s.insert(str);
		}
		str = "";
	}

	cout << s.size();

	return 0;
}