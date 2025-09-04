#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    vector<int> lst(N + 1), order(N + 1, 0);
    for (int i = 1; i <= N; i++) cin >> lst[i];

    for (int i = 1; i <= N; i++) {
        int o = lst[i];
        int pos = 1;
        while (pos <= N) {
            if (order[pos] == 0) {
                if (o == 0) break;
                o--;
            }
            pos++;
        }
        order[pos] = i;
    }

    for (int i = 1; i <= N; i++) cout << order[i] << ' ';
    return 0;
}
