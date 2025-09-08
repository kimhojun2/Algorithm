#include <iostream>

using namespace std;

int main() {
	int m, n;
	cin >> m >> n;


	int dir = 1;

	int i = 0, j = -1;

	int count = 0;

	while (true) {

		for (int pos = 0; pos < n; ++pos) {
			j += dir;
		}

		++count;
		if (--m == 0)
			break;

		for (int pos = 0; pos < m; ++pos) {
			i += dir;
		}

		++count;

		if (--n == 0)
			break;

		dir *= -1;
	}

	cout << count - 1 << endl;
}

