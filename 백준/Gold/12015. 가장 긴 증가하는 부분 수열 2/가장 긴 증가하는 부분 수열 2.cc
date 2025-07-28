#include <iostream>
#include <vector>
using namespace std;

int N;
int arr[1000000] = { 0, };
int lis[1000000] = { 0, };

int binary_search(int left, int right, int target) {
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


int lis_length() {
	int len = 0;
	for (int i = 0;i < N;i++) {
		if (len == 0 || lis[len - 1] < arr[i]) {
			lis[len] = arr[i];
			len++;
		}
		else {
			int position = binary_search(0, len, arr[i]);
			lis[position] = arr[i];
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

	cout << lis_length();

	return 0;
}