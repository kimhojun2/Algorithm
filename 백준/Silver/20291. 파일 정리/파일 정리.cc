#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
	int N;
	cin >> N;
	map<string, int>dic;
	for (int i = 0;i < N;i++) {
		string file;
		cin >> file;
		file.erase(0, file.find('.') + 1);
		dic[file]++;
	}
	for (auto i : dic) {
		cout << i.first <<' '<< i.second << '\n';
	}

	return 0;
}