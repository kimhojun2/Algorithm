#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>

using namespace std;

int N, M, K;
int energy[10][10];
int ground[10][10];

struct Tree {
    int age, y, x;

    bool operator<(const Tree& other) const {
        return age < other.age;
    }
};

int dy[8] = { -1, -1, -1, 0, 1, 1, 1, 0 };
int dx[8] = { -1, 0, 1, 1, 1, 0, -1, -1 };

deque<Tree> trees;

void spring_summer() {
    deque<Tree> temp;
    vector<Tree> die;

    for (int i = 0; i < trees.size(); i++) {
        Tree now = trees[i];
        if (ground[now.y][now.x] >= now.age) {
            ground[now.y][now.x] -= now.age;
            now.age++;
            temp.push_back(now);
        }
        else {
            die.push_back(now);
        }
    }

    for (int i = 0; i < die.size(); i++) {
        ground[die[i].y][die[i].x] += (die[i].age / 2);
    }
    trees = temp;
}

void autumn() {
    vector<Tree> baby_trees;
    for (int i = 0; i < trees.size(); i++) {
        if (trees[i].age % 5 == 0) {
            for (int d = 0; d < 8; d++) {
                int ny = trees[i].y + dy[d];
                int nx = trees[i].x + dx[d];
                if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
                baby_trees.push_back({ 1, ny, nx });
            }
        }
    }

    for (int i = 0; i < baby_trees.size(); i++) {
        trees.push_front(baby_trees[i]);
    }
}

void winter() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            ground[i][j] += energy[i][j];
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> K;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> energy[i][j];
            ground[i][j] = 5;
        }
    }

    vector<Tree> input;
    for (int i = 0; i < M; i++) {
        int r, c, z;
        cin >> r >> c >> z;
        input.push_back({ z, r - 1, c - 1 });
    }

    sort(input.begin(), input.end());

    for (int i = 0; i < input.size(); i++) {
        trees.push_back(input[i]);
    }

    while (K--) {
        spring_summer();
        autumn();
        winter();
        if (trees.empty()) break;
    }

    cout << trees.size();

    return 0;
}