#include <iostream>
using namespace std;

int prices[14];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int start;
	cin >> start;
	int jcash = start;
	int scash = start;
	int last;
	int up=0, down=0;
	for (int i = 0;i < 14;i++) {
		cin >> prices[i];
	}

	int jstock = 0;
	int sstock = 0;
	for (int i = 0;i < 14;i++) {
		int price = prices[i];
		if (jcash >= price) {
			int jcnt = jcash / price;
			jstock += jcnt;
			jcash -= (jcnt * price);
		}
		if (i == 0) {
			last = price;
			continue;
		}
		if (last > price) {
			down++;
			up = 0;
			if (down >= 3) {
				int scnt = scash / price;
				sstock += scnt;
				scash -= (scnt * price);
			}
		}
		else if (last < price) {
			up++;
			down = 0;
			if (up >= 3) {
				scash += sstock * price;
				sstock = 0;
			}
		}
		else {
			up = 0;down = 0;
		}
		last = price;
	}

	if (jcash + jstock * last > scash + sstock * last) cout << "BNP";
	else if (jcash + jstock * last < scash + sstock * last) cout << "TIMING";
	else cout << "SAMESAME";

	return 0;
}