#include <iostream>
using namespace std;

int main() {
    int a, b, c, m;
    cin >> a >> b >> c >> m;
    int n = 24;
    int answer = 0, pirodo = 0;

    while (n--) {
        if (pirodo + a <= m) {
            answer += b;
            pirodo += a;
        } else {
            pirodo -= c;
            if (pirodo < 0) pirodo = 0;
        }
    }

    cout << answer << "\n";
    return 0;
}
