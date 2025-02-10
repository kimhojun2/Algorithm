#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> N;

	int answer = 0;
	while (N != 0) {
		if (N % 5 == 0) {
			answer += N / 5;
			break;
		}
		if (N - 3 < 0) {
			answer = -1;
			break;
		}
		N -= 3;
		answer++;
	}
	cout << answer;

	return 0;
}