#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

int Map[26] = { 0, };

int main() {
    int num;
    cin >> num;
    cin.ignore();

    for (int i = 0; i < num; i++) {
        string input;
        getline(cin, input);

        memset(Map, 0, sizeof(Map));
        for (int j = 0; j < input.size(); j++) {
            if (input[j] == ' ') continue;

            Map[input[j] - 'a']++;
        }

        vector<pair<int, char>> v;
        for (int j = 0; j < 26; j++) {
            v.push_back(make_pair(Map[j], j + 'a'));
        }

        sort(v.begin(), v.end(), greater<>());

        if (v[0].first == v[1].first) {
            cout << "?\n";
        }
        else {
            cout << v[0].second << "\n";
        }
    }
}