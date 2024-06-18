#include <iostream>

using namespace std;

int main() {
	int arr[42] = { 0, };

	int now;

	for (int i = 0; i < 10; i++) {
		cin >> now;
		arr[now % 42]++;
	}
	int cnt = 0;
	for (int j = 0; j < 42; j++) {
		if (arr[j] > 0) {
			cnt++;
		}
	}
	cout << cnt;


	return 0;
}
