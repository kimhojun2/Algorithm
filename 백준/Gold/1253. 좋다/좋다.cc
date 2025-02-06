#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N;
	cin >> N;
	vector<int> arr;
	for (int i = 0;i < N;i++) {
		int num;
		cin >> num;
		arr.push_back(num);
	}

	sort(arr.begin(), arr.end());

	int ans = 0;
	for (int idx = 0; idx < N; idx++) {
		int target = arr[idx];
		int left = 0;
		int right = N - 1;
		while (left < right) {
			if (left == idx) {
				left++;
				continue;
			}
			if (right == idx) {
				right--;
				continue;
			}
			int now = arr[left] + arr[right];
			if (now == target) {
				ans++;
				break;
			}
			else if (now > target) {
				right--;

			}
			else {
				left++;

			}

		}
	}
	cout << ans;

	return 0;
}