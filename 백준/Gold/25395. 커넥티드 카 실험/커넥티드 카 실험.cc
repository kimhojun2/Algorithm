#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, S;
    cin >> N >> S;

    vector<pair<int, pair<int, int>>> arr; 
    vector<bool> visit(N + 1, false);
    queue<pair<int, pair<int, int>>> q;  
    for (int i = 0; i < N; i++) {
        int locate;
        cin >> locate;
        arr.emplace_back(locate, make_pair(i + 1, 0)); 
    }

    for (int i = 0; i < N; i++) {
        cin >> arr[i].second.second;
    }

    sort(arr.begin(), arr.end());

    q.push(arr[S - 1]);  
    visit[S] = true;

    while (!q.empty()) {
        auto cur = q.front();
        q.pop();

        int cur_idx = cur.second.first;   
        int cur_locate = cur.first;       
        int cur_fuel = cur.second.second; 

        for (int i = cur_idx - 2; i >= 0; i--) {  
            if (arr[i].first < cur_locate - cur_fuel) {  
                break;
            }
            if (visit[arr[i].second.first]) {
                continue;
            }
            q.push(arr[i]);
            visit[arr[i].second.first] = true;
        }
        for (int i = cur_idx; i < N; i++) {
            if (arr[i].first > cur_locate + cur_fuel) { 
                break;
            }
            if (visit[arr[i].second.first]) {
                continue;
            }
            q.push(arr[i]);
            visit[arr[i].second.first] = true;
        }
    }
    for (int i = 1; i <= N; i++) {
        if (visit[i]) {
            cout << i << " ";
        }
    }
    cout << "\n";

    return 0;
}
