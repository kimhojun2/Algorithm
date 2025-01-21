#include <iostream>
#include <set>
using namespace std;

int main() {
	string input = " ";
	set<char> vowels = {'a','e','i','o','u'};
	//consonant
	while (true) {
		cin >> input;

		if (input == "end") {
			break;
		}
		bool vowel = false;
		bool error = false;
		int v_cnt = 0;
		int c_cnt = 0;
		char last = 'A';
		for (int i = 0;i < input.size();i++) {
			if (input[i] == last && (input[i] != 'e'&&input[i]!='o')) {
				error = true;
				break;
			}

			if (vowels.count(input[i])) {
				vowel = true;
				v_cnt++;
				c_cnt = 0;
			}
			else {
				v_cnt = 0;
				c_cnt++;
			}
			if (c_cnt == 3 || v_cnt == 3) {
				error = true;
				break;
			}
			last = input[i];
		}
		if (!vowel || error) {
			cout << "<" << input << "> is not acceptable." << '\n';
		}
		else {
			cout << "<" << input << "> is acceptable." << '\n';
		}
		vowel = false;
		error = false;
	}

	return 0;
}