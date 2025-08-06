#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, K;
vector<int> arr;
vector<int> diff;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;
    arr.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    // 1. 오름차순 정렬
    sort(arr.begin(), arr.end());

    // 2. 인접한 키 차이 저장
    for (int i = 1; i < N; i++) {
        diff.push_back(arr[i] - arr[i - 1]);
    }

    // 3. 오름차순 정렬
    sort(diff.begin(), diff.end());

    // 4. 앞에서 (N - K)개의 작은 차이만 더함 (뒤의 K-1개 큰 값은 제거)
    int answer = 0;
    for (int i = 0; i < N - K; i++) {
        answer += diff[i];
    }

    cout << answer << '\n';
    return 0;
}
