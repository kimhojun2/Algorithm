#include <iostream>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    map<char, int> dic;
    string word;
    cin >> word;

    for (char c : word) {
        dic[c]++;
    }

    bool check = false;
    char middle = '\0';
    string half = "";

    for (auto i = dic.begin(); i != dic.end(); ++i) {
        if (i->second % 2 == 1) {
            if (!check) {
                check = true;
                middle = i->first;
            }
            else {
                cout << "I'm Sorry Hansoo";
                return 0;
            }
        }
        half.append(i->second / 2, i->first);
    }

    sort(half.begin(), half.end());
    string ans = half;
    if (check) {
        ans += middle;
    }
    reverse(half.begin(), half.end());
    ans += half;

    cout << ans;
    return 0;
}
