#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> scores(N);
    float max_value = 0;

    for (int i = 0; i < N; i++) {
        cin >> scores[i];
        if (scores[i] > max_value) {
            max_value = scores[i];
        }
    }

    float new_total = 0;
    for (int i = 0; i < N; i++) {
        new_total += (scores[i] / max_value) * 100;
    }

    float new_average = new_total / N;
    cout << new_average << '\n';

    return 0;
}
