#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int N, K;
	cin >> N >> K;
	int zero = 0;
	int cnt = 0;
	vector<pair<int, int>> arr(2 * N);
	for (int i = 0;i < 2 * N;i++) {
		cin >> arr[i].first;
	}
	while (zero < K) {
		cnt++;

		rotate(arr.rbegin(), arr.rbegin() + 1, arr.rend());

		if (arr[N - 1].second == 1) {
			arr[N - 1].second = 0;
		}

		for (int i = N - 2;i >= 0;i--) {
			if (arr[i].second == 1) {
				if (arr[i+1].second ==0 && arr[i + 1].first > 0) {
					arr[i].second = 0;
					arr[i + 1].second = 1;
					arr[i + 1].first--;
					if (arr[i + 1].first == 0) {
						zero++;
					}
					if (i == N - 2) {
						arr[N - 1].second = 0;
					}
				}
			}
			//if (zero >= K) {
			//	break;
			//}
		}
		if (arr[0].first > 0) {
			arr[0].first--;
			arr[0].second = 1;
			if (arr[0].first == 0) {
				zero++;
			}
		}

	}
	cout << cnt;

	return 0;
}