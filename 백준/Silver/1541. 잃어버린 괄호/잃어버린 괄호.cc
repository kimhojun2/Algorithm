#include <iostream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string S;
    cin >> S;

    int ans = 0;
    string num = "";
    bool minus = false;

    for (int i = 0; i <= S.size(); i++) {
        char now = (i == S.size() ? '-' : S[i]);

        if (now == '+' || now == '-') {
            if (minus) ans -= stoi(num);
            else ans += stoi(num);
            num.clear();

            if (now == '-') minus = true;
        }
        else {
            num += now;
        }
    }

    cout << ans;
    return 0;
}
