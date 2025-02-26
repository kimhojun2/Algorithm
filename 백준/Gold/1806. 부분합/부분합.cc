#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int N, S;
	cin >> N >> S;
	vector<int>arr;
	for (int i = 0;i < N;i++) {
		int num;
		cin >> num;
		arr.push_back(num);
	}
	int answer = 0;
	int left = 0;
	int right = 0;
	int sum = 0;
	while (right < N) {
		sum += arr[right];

		while (sum >= S) {
			if (answer == 0) {
				answer = right - left+1;
			}
			else {
				answer = min(answer, right - left+1);
				sum -= arr[left];
				left++;
			}
		}
		right++;
	}
	cout << answer;

	return 0;
}