#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
int arr[100000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0;i < N;i++) {
		cin >> arr[i];
	}
	sort(arr, arr + N);

	int left_idx = 0;
	int right_idx = N-1;
	int ans = 2e9;
	pair<int, int>idx;

	while (left_idx < right_idx) {
		int now = arr[right_idx] + arr[left_idx];
		if (abs(now) < ans) {
			ans = abs(now);
			idx.first = arr[left_idx];
			idx.second = arr[right_idx];
		}
		if (now == 0) break;

		if (now > 0)right_idx--;
		else left_idx++;
	}

	cout << idx.first << " " << idx.second;


	return 0;
}