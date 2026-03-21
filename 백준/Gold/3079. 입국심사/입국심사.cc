#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M;
int arr[100000];

bool check(long long t) {
	
	long long cnt = 0;

	for (int i = 0;i < N;i++) {
		cnt += (t / arr[i]);
		if (cnt >= M) return true;
	}
	if (cnt >= M) return true;
	else return false;
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 0;i < N;i++) {
		cin >> arr[i];
	}

	long long low = 1;
	long long high = 1e18;
	
	long long min_time = 1e18;

	while (low <= high) {
		long long mid = low + (high - low) / 2;

		if (check(mid)) {
			min_time = mid;
			high = mid - 1;
		}
		else low = mid + 1;

	}

	cout << min_time;

	return 0;
}