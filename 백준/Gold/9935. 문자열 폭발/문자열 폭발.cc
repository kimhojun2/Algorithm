#include <iostream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string S, target;
    cin >> S >> target;

    string result = "";
    int t_size = target.size();

    for (char ch : S) {
        result += ch;

        if (result.size() >= t_size && result.substr(result.size() - t_size) == target) {
            result.erase(result.size() - t_size);
        }
    }

    cout << (result.empty() ? "FRULA" : result) << "\n";

    return 0;
}