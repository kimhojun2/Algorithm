#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N;
    cin >> N;

    int answer = -1;
    int five_coin = N / 5;
    int remain = N % 5;

    while (five_coin >= 0) {
        if (remain % 2 == 0) { 
            answer = five_coin + (remain / 2);
            break;
        }
        five_coin--;
        remain += 5;
    }

    cout << answer;
    return 0;
}
