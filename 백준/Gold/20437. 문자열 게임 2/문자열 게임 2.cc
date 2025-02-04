#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int T;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> T;
    for (int i = 0; i < T; i++) {
        string W;
        int K;
        cin >> W >> K;
        map<char, vector<int>> dic;

        for (int idx = 0; idx < W.length(); idx++) {
            dic[W[idx]].push_back(idx);
        }

        int short_ = -1;
        int long_ = -1;

        for (auto it : dic) {
            vector<int>& indices = it.second;
            if (indices.size() >= K) {
                for (int j = 0; j <= indices.size() - K; j++) {
                    int length = indices[j + K - 1] - indices[j] + 1;
                    if (short_ == -1 || length < short_) short_ = length;
                    if (long_ == -1 || length > long_) long_ = length;
                }
            }
        }
        if (short_ == -1 || long_ == -1) {
            cout << -1 << '\n';
        }
        else {
            cout << short_ << " " << long_ << "\n";
        }

    }

    return 0;
}
