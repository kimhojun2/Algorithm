#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, C;
int arr[200000];


bool check(int dist) {
	int cnt = 1;
	int last_pos = arr[0];

	for (int i = 1;i < N;i++) {
		if (arr[i] - last_pos >= dist) {
			cnt++;
			last_pos = arr[i];
		}
	}

	return cnt >= C;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> C;
	for (int i = 0;i < N;i++) {
		cin >> arr[i];
	}

	sort(arr, arr + N);
	int low = 1;
	int high = 1000000000;
	int ans = 1;

	while (low <= high) {
		int mid = low + (high - low) / 2;

		if (check(mid)) {
			ans = max(ans, mid);
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
		
	}

	cout << ans;

	return 0;
}