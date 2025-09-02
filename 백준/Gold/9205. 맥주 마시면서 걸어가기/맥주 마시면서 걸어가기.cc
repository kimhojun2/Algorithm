#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;

	for (int i = 0;i < T;i++) {
		int n;
		cin >> n;
		vector<pair<int, int>>nodes;
		vector<int>visited(n,0);
		int sx, sy, gx, gy;
		for (int j = 0;j < n+2;j++) {
			int x, y;
			cin >> x >> y;
			if (j == 0) {
				sx = x, sy = y;
			}
			else if (j == n + 1) {
				gx = x, gy = y;
			}
			else {
				nodes.push_back({ x,y });
			}
		}
		queue<pair<int,int>>q;
		q.push({ sx,sy });
		bool ans = false;
		while (!q.empty()) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			if (abs(gx - x) + abs(gy - y) <= 1000) {
				ans = true;
				break;
			}
			for (int k=0;k < n;k++) {
				if (visited[k]) continue;
				if (abs(nodes[k].first - x) + abs(nodes[k].second - y) <= 1000) {
					q.push({ nodes[k].first, nodes[k].second });
					visited[k] = 1;
				}
			}

		}
		if (ans) cout << "happy" << '\n';
		else cout << "sad" << '\n';
		

	}

	return 0;
}