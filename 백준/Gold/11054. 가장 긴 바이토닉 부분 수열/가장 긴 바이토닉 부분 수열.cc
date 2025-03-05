#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int arr[1000] = { 0, };
int dp[1000][2] = { 0, };

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N;
    cin >> N;

    for (int i = 0;i < N;i++) {
        cin >> arr[i];
    }
    int answer = 1;
    for (int i = 0;i < N;i++) {
        dp[i][0] = 1;
        dp[i][1] = dp[i][0];
        for (int j = 0;j < i;j++) {
            if (arr[j] < arr[i]) {
                dp[i][0] = max(dp[i][0], dp[j][0] + 1);
                answer = max(answer, dp[i][0]);
            }
            else if (arr[j] > arr[i]) {
                dp[i][1] = max(dp[i][1], dp[j][1] + 1);
                dp[i][1] = max(dp[i][1], dp[j][0] + 1);
                answer = max(answer, dp[i][1]);
            }
        }
    }

    cout << answer;

    return 0;
}
