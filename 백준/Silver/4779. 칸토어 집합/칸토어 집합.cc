#include <iostream>
#include <cmath>
using namespace std;

void func(int n) {
	int size = pow(3, n - 1);
	if (n == 0) {
		cout << "-";
		return;
	}

	func(n - 1);
	for (int i = 0; i < size; i++) {
		cout << " ";
	}
	func(n - 1);

}

int main() {
	int N;

	while (cin >> N) {
		func(N);
		cout << "\n";
	}

	return 0;
}