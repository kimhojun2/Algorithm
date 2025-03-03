#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int lcs[1001][1001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	string str1, str2;
	cin >> str1 >> str2;

	str1 = "0" + str1;
	str2 = "0" + str2;

	int len_str1 = str1.size();
	int len_str2 = str2.size();

	for (int i = 0; i < len_str1; i++) {
		for (int j = 0; j < len_str2; j++) {
			if (i == 0 || j == 0) {
				lcs[i][j] = 0;
				continue;
			}
			if (str1[i] == str2[j])
				lcs[i][j] = lcs[i - 1][j - 1] + 1;
			else
				lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
		}
	}

	cout << lcs[len_str1 - 1][len_str2 - 1];

	return 0;
}
