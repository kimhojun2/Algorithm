#include <iostream>

using namespace std;

int main() {
	long X;
	int N;
	int a, b;

	cin >> X;
	cin >> N;
	
	for (int i = 0; i < N; i++) {
		cin >> a >> b;
		X -= (a * b);
	}
	
	if (X == 0) {
		cout << "Yes";
	}
	else
		cout << "No";

	return 0;
}