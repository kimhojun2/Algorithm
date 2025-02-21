#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N, M;
    cin >> N >> M;

    int limit = (9 * M + 9) / 10; 

    vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    map<int, int> ans; 
    int max_value = 0;  

    for (int i = 0; i < M; i++) {
        ans[arr[i]]++;
        max_value = max(max_value, ans[arr[i]]);
    }


    if (max_value >= limit) {
        cout << "YES";
        return 0;
    }

    for (int left = 0, right = M; right < N; left++, right++) {
        int left_value = arr[left];
        int right_value = arr[right];

        ans[left_value]--;
        ans[right_value]++;
        max_value = max(max_value, ans[right_value]);


        if (max_value >= limit) {
            cout << "YES";
            return 0;
        }
    }

    cout << "NO";
    return 0;
}
