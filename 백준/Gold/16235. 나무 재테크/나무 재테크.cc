#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, K;
int dy[] = { -1,-1,-1,0,0,1,1,1 };
int dx[] = { -1,0,1,-1,1,-1,0,1 };

vector<int> trees[10][10];

void Cycle(vector<vector<int>>& ground, vector<vector<int>>& add_manure) {
    vector<int> new_trees[10][10];
    vector<int> dead_trees[10][10];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (trees[i][j].empty()) continue;
            sort(trees[i][j].begin(), trees[i][j].end());
            vector<int> survived;
            int& manure = ground[i][j];

            for (int age : trees[i][j]) {
                if (manure >= age) {
                    manure -= age;
                    survived.push_back(age + 1);
                }
                else {
                    dead_trees[i][j].push_back(age);
                }
            }
            trees[i][j] = survived;
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int age : dead_trees[i][j]) {
                ground[i][j] += (age / 2);
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int age : trees[i][j]) {
                if (age % 5 != 0) continue;
                for (int d = 0; d < 8; d++) {
                    int ny = i + dy[d];
                    int nx = j + dx[d];
                    if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
                    new_trees[ny][nx].push_back(1);
                }
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            trees[i][j].insert(trees[i][j].end(), new_trees[i][j].begin(), new_trees[i][j].end());
            ground[i][j] += add_manure[i][j];
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N >> M >> K;
    vector<vector<int>> ground(N, vector<int>(N, 5));
    vector<vector<int>> add_manure(N, vector<int>(N, 0));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> add_manure[i][j];
        }
    }

    for (int i = 0; i < M; i++) {
        int y, x, age;
        cin >> y >> x >> age;
        trees[y - 1][x - 1].push_back(age);
    }

    for (int i = 0; i < K; i++) {
        Cycle(ground, add_manure);
    }

    int tree_count = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            tree_count += trees[i][j].size();
        }
    }
    cout << tree_count;
    return 0;
}