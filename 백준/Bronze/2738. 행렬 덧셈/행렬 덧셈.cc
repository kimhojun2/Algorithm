#include <iostream>

using namespace std;

int arr[101][101], arr2[101][101];

int main() {
	int N, M;
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
			cin >> arr[i][j];
	}
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
			cin >> arr2[i][j];
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
			cout << arr[i][j] + arr2[i][j] << ' ';
		cout << '\n';
	}
	
	return 0;

}