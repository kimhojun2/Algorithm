#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	
	vector<int>arr(N, 0);
	for (int i = 0;i < N;i++) {
		cin >> arr[i];
	}

	sort(arr.begin(), arr.end());

	int left = 0, right = N-1, ans_left = 0, ans_right = N-1;
	int ans = abs(arr[left] + arr[right]);
	
	while (left < right) {
		int now = arr[left] + arr[right];
		if (abs(now) < ans) {
			ans = abs(now);
			ans_left = left;
			ans_right = right;
		}
		if (now < 0)left++;
		else right--;

	}

	cout << arr[ans_left] << " " << arr[ans_right];

	return 0;
}