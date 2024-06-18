#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int N;
    int max_value = -1000000;
    int min_value = 1000000;
    int now;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> now;
        max_value = max(max_value, now);
        min_value = min(min_value, now);
    }
    cout << min_value << ' ' << max_value;

    return 0;
}
