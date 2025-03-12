#include <iostream>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N;
    cin >> N;

    string sound;
    cin >> sound;

    int L = sound.size();
    int left = 0, right = 0;
    int ans = 0;
    map<char, int> dic;
    int unique_cnt = 0;

    while (right < L) {
        char now = sound[right];

        if (dic[now] == 0) unique_cnt++;
        dic[now]++;
        right++;

        while (unique_cnt > N) {
            dic[sound[left]]--;
            if (dic[sound[left]] == 0) unique_cnt--;
            left++;
        }

        ans = max(ans, right - left);
    }

    cout << ans << '\n';
    return 0;
}
