#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int V, E;
const int INF = 1e9;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> V >> E;
	vector<vector<int>>distance(V + 1, vector<int>(V + 1, INF));
	for (int i = 0;i < E;i++) {
		int a, b, c;
		cin >> a >> b >> c;
		distance[a][b] = c;
	}

	for (int k = 1;k <= V;k++) {
		for (int i = 1;i <= V;i++) {
			for (int j = 1;j <= V;j++) {
				distance[i][j] = min(distance[i][j], distance[i][k] + distance[k][j]);
			}
		}
	}

	int ans = INF;
	for (int i = 1;i <= V;i++) {
		ans = min(ans, distance[i][i]);
	}

	if (ans == INF) cout << -1;
	else cout << ans;

	return 0;
}