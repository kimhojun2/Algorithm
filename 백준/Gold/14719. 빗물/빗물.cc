#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

int blocks[501] = { 0, };

int main() {
	int H, W;
	cin >> H >> W;

	for (int i = 0;i < W;i++) {
		cin >> blocks[i];
	}
	int ans = 0;
	for (int i = 1;i < W - 1;i++) {
		int left_max = 0;
		int right_max = 0;
		for (int l = 0;l < i;l++) {
			left_max = max(blocks[l], left_max);
		}
		for (int r = i + 1;r < W;r++) {
			right_max = max(blocks[r], right_max);
		}
		if (min(left_max, right_max) - blocks[i] > 0) {
			ans += min(left_max, right_max) - blocks[i];
		}
	}

	cout << ans;

	return 0;
}