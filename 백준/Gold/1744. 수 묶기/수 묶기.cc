#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> positive, negative;
    int one = 0, zero = 0;
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        if (num > 1) positive.push_back(num);
        else if (num == 1) one++;
        else if (num == 0) zero++;
        else negative.push_back(num);
    }

    sort(positive.begin(), positive.end(), greater<>());
    sort(negative.begin(), negative.end());

    int result = 0;

    for (int i = 0; i + 1 < positive.size(); i += 2)
        result += positive[i] * positive[i + 1];
    if (positive.size() % 2 == 1)
        result += positive.back();

    for (int i = 0; i + 1 < negative.size(); i += 2)
        result += negative[i] * negative[i + 1];
    if (negative.size() % 2 == 1 && zero == 0)
        result += negative.back();

    result += one;

    cout << result;
    return 0;
}
