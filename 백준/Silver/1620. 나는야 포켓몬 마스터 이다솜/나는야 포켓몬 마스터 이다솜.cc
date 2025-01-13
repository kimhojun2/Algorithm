#include <iostream>
#include <map>
#include <cctype>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, M;
	cin >> N >> M;
	
	map<string, int>name_to_number;
	map<int, string>number_to_name;

	string name;
	for (int i = 1;i <= N;i++) {
		cin >> name;
		name_to_number[name] = i;
		number_to_name[i] = name;
	}
	string check;
	for (int i = 0;i < M;i++) {
		cin >> check;
		if (isdigit(check[0])) {
			cout << number_to_name[stoi(check)] <<'\n';
		}
		else {
			cout << name_to_number[check] << '\n';
		}
	}

	return 0;
}