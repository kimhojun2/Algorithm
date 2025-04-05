#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
int arr[8];
vector<int> v;
bool visited[8] = { 0, };

void dfs(int idx, int cnt) {
    if (cnt == m) {
        for (int i = 0; i < m; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }
    int tmp = 0;
    for (int i = idx; i < v.size(); i++) {
        if (!visited[i] && v[i]!=tmp) {
            visited[i] = true;
            arr[cnt] = v[i];
            tmp = arr[cnt];
            dfs(i,cnt + 1);
            visited[i] = false;
        }
    }
}

int main() {
    cin >> n >> m;

    v.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    dfs(0,0);
    return 0;
}