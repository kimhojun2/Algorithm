#include <iostream>
#include <string>
using namespace std;

int main() {
	int T;
	cin >> T;
	for (int i = 0;i < T;i++) {
		string S;
		cin >> S;
		cout << S[0] << S[S.size()-1]<<'\n';
	}


	return 0;
}