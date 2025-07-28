#include <iostream>
#include <vector>
using namespace std;

int N;
int arr[1000000] = { 0, };
int lis[1000000] = { 0, };

int binary_search(int right, int target) {
	int left = 0;
	while (left < right) {
		int mid = (left + right) / 2;
		if (lis[mid] < target) {
			left = mid + 1;
		}
		else {
			right = mid;
		}
	}
	
	return right;
}

int LIS() {
	int len = 0;
	for (int i = 0;i < N;i++) {
		if (len == 0 || lis[len - 1] < arr[i]) {
			lis[len] = arr[i];
			len++;
		}
		else {
			int pos = binary_search(len, arr[i]);
			lis[pos] = arr[i];
		}
	}

	return len;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	for (int i = 0;i < N;i++) {
		cin >> arr[i];
	}

	cout << LIS();

	return 0;
}