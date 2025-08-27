#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

char ahdmas[] = { 'a','e','i','o','u' };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string now;

	while (1) {
		cin >> now;
		if (now == "end") break;
		bool rule1 = false;
		bool rule2 = true;
		bool rule3 = true;
		int rule2_a = 0;
		int rule2_b = 0;
		char before = 'A';
		for (char check : now) {
			if (find(ahdmas, ahdmas + 5, check) != ahdmas + 5) {
				rule1 = true;
				if (rule2_a == 2) {
					rule2 = false; break;
				}
				else {
					rule2_a++;
					rule2_b = 0;
				}
			}
			else {
				if (rule2_b == 2) {
					rule2 = false; break;
				}
				else {
					rule2_b++;
					rule2_a = 0;
				}
			}
			if (check == before && check != 'e' && check != 'o') {
				rule3 = false; break;
			}
			before = check;
		}
		if (rule1 && rule2 && rule3) cout << '<' << now << '>' << " is acceptable." << '\n';
		else cout << '<' << now << '>' << " is not acceptable." << '\n';
	}


	return 0;
}