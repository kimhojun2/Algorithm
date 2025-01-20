#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <limits>  // 추가: numeric_limits를 사용하기 위한 헤더

using namespace std;

int N;

int bfs(vector<vector<int>>& arr, int start) {
    vector<int> visited(N + 1, 0);
    queue<int> q;
    q.push(start);
    visited[start] = 1;

    while (!q.empty()) {
        int now = q.front();
        q.pop();
        for (int i = 0; i < arr[now].size(); i++) {
            auto next = arr[now][i];
            if (!visited[next]) {
                visited[next] = visited[now] + 1;
                q.push(next);
            }
        }
    }
    int max = *max_element(visited.begin(), visited.end());

    return max - 1;
}

int main() {
    cin >> N;
    int s = 0, e = 0;

    vector<vector<int>> arr(N + 1);

    while (true) {
        cin >> s >> e;
        if (s == -1 && e == -1) {
            break;
        }
        arr[s].push_back(e);
        arr[e].push_back(s);
    }
    vector<int> lst;

    int min_value = std::numeric_limits<int>::max();

    for (int i = 1; i <= N; i++) {
        int value = bfs(arr, i);
        if (value < min_value) {
            min_value = value;
            lst.clear();
            lst.push_back(i);
        }
        else if (value == min_value) {
            lst.push_back(i);
        }
    }

    cout << min_value << " " << lst.size() << '\n';
    for (int i = 0; i < lst.size(); i++) {
        cout << lst[i] << " ";
    }

    return 0;
}
