#include <iostream>
using namespace std;


int k;
int s[13] = { 0, };
int ans[6] = { 0, };

void lotto(int start, int level) {

	if (level == 6) {
		for (int i = 0;i < 6;i++) {
			cout << ans[i] << " ";
		}
		cout << '\n';
		return;
	}


	for (int i = start;i < k;i++) {
		ans[level] = s[i];
		lotto(i+1, level + 1);
	}

}



int main() {


	while (1) {
		cin >> k;
		if (k==0) {
			break;
		}
		for (int i = 0;i < k;i++) {
			cin >> s[i];
		}

		lotto(0, 0);

		cout << '\n';

	}

	return 0;
}