#include <iostream>
#include <deque>
#include <vector>

#define MAX_SIZE 100001

using namespace std;

void BFS(int N, int K) {
    vector<int> visited(MAX_SIZE, 0);
    vector<int> distance(MAX_SIZE, 0);
    deque<int> queue;

    queue.push_back(N);
    bool found = false;

    if (N == K) {
        cout << 0 << '\n';
        return;
    }

    while (!queue.empty()) {
        if (found) break;

        int t = queue.front();
        queue.pop_front();

        for (int i : {t - 1, t + 1, t * 2}) {
            if (i >= 0 && i < MAX_SIZE) {
                if (visited[i] == 0) {
                    if (i == t * 2) {
                        distance[i] = distance[t];
                        queue.push_front(i);
                    }
                    else {
                        distance[i] = distance[t] + 1;
                        queue.push_back(i);
                    }
                    visited[i] = 1;
                }
                else {
                    if (distance[i] >= distance[t] + 1) {
                        if (i == t * 2) {
                            distance[i] = distance[t];
                            queue.push_front(i);
                        }
                        else {
                            distance[i] = distance[t] + 1;
                            queue.push_back(i);
                        }
                    }
                }
            }
        }
    }

    cout << distance[K] << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K;
    cin >> N >> K;
    BFS(N, K);

    return 0;
}
