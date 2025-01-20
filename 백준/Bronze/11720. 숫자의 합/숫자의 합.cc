#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;

	string str;
	cin >> str;

	int sum=0;

	for (int i = 0;i < str.size();i++) {
		int now = str[i]-'0';
		sum += now;
	}

	cout << sum;


	return 0;
}