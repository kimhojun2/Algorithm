#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cmath>
#include <algorithm>
using namespace std;

int N;
map<char, int>weight;
int ans = 0;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0;i < N;i++) {
		string now;
		cin >> now;
		int len = now.length() - 1;
		for (int j = 0;j <= len;j++) {
			weight[now[j]] += pow(10, len - j);
		}
	}
	vector<int>num;
	for (auto p : weight) {
		num.push_back(p.second);
	}
	
	sort(num.rbegin(), num.rend());

	int mul = 9;
	for (int n : num) {
		ans += n * mul;
		mul--;
	}
	cout << ans;

	return 0;
}