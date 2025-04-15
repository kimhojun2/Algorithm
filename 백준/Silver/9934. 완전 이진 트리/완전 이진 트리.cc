#include <iostream>
#include <vector>
using namespace std;

void dfs(const vector<int>& inorder, int depth, vector<vector<int>>& answer) {
    int mid = inorder.size() / 2;
    answer[depth].push_back(inorder[mid]);

    if (inorder.size() == 1) return;

    vector<int> left(inorder.begin(), inorder.begin() + mid);
    vector<int> right(inorder.begin() + mid + 1, inorder.end());

    dfs(left, depth + 1, answer);
    dfs(right, depth + 1, answer);
}

int main() {
    int k;
    cin >> k;

    int nodeCount = (1 << k) - 1; // 2^k - 1
    vector<int> inorder(nodeCount);

    for (int i = 0; i < nodeCount; ++i) {
        cin >> inorder[i];
    }

    vector<vector<int>> answer(k);
    dfs(inorder, 0, answer);

    for (const auto& level : answer) {
        for (int num : level) {
            cout << num << ' ';
        }
        cout << '\n';
    }

    return 0;
}
