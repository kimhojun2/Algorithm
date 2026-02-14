#include <iostream>
#include <algorithm>
using namespace std;

int T;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;
	while (T--) {
		long long x1, y1, r1, x2, y2, r2;
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

		long long dx = x1 - x2;
		long long dy = y1 - y2;
		long long d2 = dx * dx + dy * dy;

		if (dx == 0 && dy == 0) {
			if (r1 == r2) cout << -1 << '\n';
			else cout << 0 << '\n';
			continue;
		}

		long long sum = r1 + r2;
		long long diff = llabs(r1 - r2);

		long long sum2 = sum * sum;
		long long diff2 = diff * diff;

		if (d2 > sum2) cout << 0 << '\n';
		else if (d2 == sum2) cout << 1 << '\n';
		else {
			if (d2 < diff2) cout << 0 << '\n';
			else if (d2 == diff2) cout << 1 << '\n';
			else cout << 2 << '\n';
		}
	}

	return 0;
}
