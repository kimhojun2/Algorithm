#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <climits>

using namespace std;

vector<pair<int, int>> chickens;
vector<pair<int, int>> houses;
vector<pair<int, int>> selected;

int N, M;
int minCityDistance = INT_MAX;

void dfs(int start, int level) {
    if (level == M) {
        int totalDistance = 0;
        for (auto& house : houses) {
            int hx = house.first;
            int hy = house.second;
            int minDist = INT_MAX;
            for (auto& chicken : selected) {
                int cx = chicken.first;
                int cy = chicken.second;
                int dist = abs(hx - cx) + abs(hy - cy);
                minDist = min(minDist, dist);
            }
            totalDistance += minDist;
        }
        minCityDistance = min(minCityDistance, totalDistance);
        return;
    }

    for (int i = start; i < chickens.size(); i++) {
        selected.push_back(chickens[i]);
        dfs(i + 1, level + 1);
        selected.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    vector<vector<int>> graph(N, vector<int>(N, 0));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> graph[i][j];
            if (graph[i][j] == 2) chickens.push_back({ i, j });
            else if (graph[i][j] == 1) houses.push_back({ i, j });
        }
    }

    dfs(0, 0);
    cout << minCityDistance << '\n';
    return 0;
}
