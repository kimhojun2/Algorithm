#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, k, s;
vector<int>adj[401];
const int INF = 1e9;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;

	vector<vector<int>>distance(n+1,vector<int>(n+1,INF));

	for (int i = 1; i <= n; i++) {
		distance[i][i] = 0;
	}

	for (int i = 0;i < k;i++) {
		int a, b;
		cin >> a >> b;
		distance[a][b] = 1;
	}

    for (int mid = 1; mid <= n; mid++) {
        for (int i = 1; i <= n; i++) {
            if (distance[i][mid] == INF) continue;
            for (int j = 1; j <= n; j++) {
                if (distance[mid][j] == INF) continue;
                distance[i][j] = min(distance[i][j], distance[i][mid] + distance[mid][j]);
            }
        }
    }

    int s;
    cin >> s;

    for (int i = 0; i < s; i++) {
        int x, y;
        cin >> x >> y;

        if (distance[x][y] != INF) cout << -1 << '\n';
        else if (distance[y][x] != INF) cout << 1 << '\n';
        else cout << 0 << '\n';
    }

    return 0;
}