#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, X;
int arr[250000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> X;
	for (int i = 0;i < N;i++) {
		cin >> arr[i];
	}

	int max_visited = 0;
	for (int i = 0;i < X;i++) max_visited += arr[i];
	int before = max_visited;
	int cnt = 1;
	int start = 1;
	while (start + X <= N) {
		int now_visited = before - arr[start - 1] + arr[start + X-1];

		if (now_visited > max_visited) {
			max_visited = now_visited;
			cnt = 1;
		}
		else if (now_visited == max_visited) cnt++;
		before = now_visited;
		start++;
	}
	if (max_visited == 0) cout << "SAD";
	else {
		cout << max_visited << '\n';
		cout << cnt;
	}


	return 0;
}