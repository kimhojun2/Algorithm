#include <iostream>
#include <map>

using namespace std;

int main() {

	int N;
	map <string, string, greater<>>m;
	string str, state;

	cin >> N;
	for (int i = 0;i < N;i++) {
		cin >> str >> state;
		m[str] = state;
	}

	map<string, string>::iterator it;
	for (it = m.begin();it != m.end();it++) {
		if (it->second == "enter") {
			cout << it->first << "\n";
		}
	}

	return 0;
}