#include <iostream>
#include <string>
#include <vector>
#include <deque>
using namespace std;

int T;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;

	for (int tc = 0;tc < T;tc++) {
		string P;
		cin >> P;
		int n;
		cin >> n;
		deque<string>dic;
		string arr;
		cin >> arr;
		string now = "";
		for (char nn : arr) {
			if ('0' <= nn && nn <= '9') {
				now += nn;
			}
			else {
				if (now != "") {
					dic.push_back(now);
					now = "";
				}
			}
		}
		bool f = true;
		bool bp = true;
		for (char p : P) {
			if (p == 'R') {
				f = !f;
			}
			else {
				if (dic.empty()) {
					cout << "error" << '\n';
					bp = false;
					break;
				}
				if (f) dic.pop_front();
				else dic.pop_back();
			}
		}
		if (bp) {
			cout << '[';
			if (f) {
				for (int i = 0; i<dic.size();i++) {
					if (i != dic.size()-1) {
						cout << dic[i] << ',';
					}
					else {
						cout << dic[i];
					}
				}
			}
			else {
				for (int i = dic.size() - 1; i >= 0;i--) {
					if (i != 0) {
						cout << dic[i]<<',';
					}
					else {
						cout << dic[i];
					}
				}
			}
			cout << ']' << '\n';
		}

	}


	return 0;
}