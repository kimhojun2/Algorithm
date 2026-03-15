#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	vector<long long>road(N-1);
	vector<long long>city(N);
	for (int i = 0;i < N-1;i++) {
		cin >> road[i];
	}
	for (int i = 0;i < N;i++) {
		cin >> city[i];
	}

	long long ans = city[0] * road[0];
	long long price = city[0];
	for (int i = 1;i < N - 1;i++){
		price = min(price, city[i]);
		ans += (price * road[i]);
	}

	cout << ans;

	return 0;
}