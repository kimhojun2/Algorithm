#include <iostream>

using namespace std;

int main() {

	int N, v;
	int arr[101] = { 0, };

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	cin >> v;

	int count=0;

	for (int j = 0; j < N; j++) {
		if (arr[j] == v) {
			count++;
		}
	}

	cout << count;

	return 0;
}