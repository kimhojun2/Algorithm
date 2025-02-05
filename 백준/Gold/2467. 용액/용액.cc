#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int arr[100000] = { 0, };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N;
	cin >> N;
	for (int i = 0;i < N;i++) {
		cin >> arr[i];
	}

	int left = 0;
	int right = N - 1;
	int value = 2e10;
	int best_left=arr[left], best_right = arr[right];
	while (left < right) {
		int now = arr[left] + arr[right];
		
		if (abs(now) < value) {
			value = abs(now);
			best_left = arr[left];
			best_right = arr[right];
		}
		
		
		if (now == 0) break;
		else if (now > 0) right--;
		else left++;

	}
	cout << best_left << ' ' << best_right;


	return 0;
}