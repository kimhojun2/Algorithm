#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;

int T;
int dy[4] = { 0,0,1,-1 };
int dx[4] = { 1,-1,0,0 };
vector<string>arr;
int start_y, start_x;

int bfs(int w, int h, queue<pair<int,int>>q_fire) {
	queue<pair<int, int>>qs;
	vector<vector<int>>visited(h, vector<int>(w, 0));
	visited[start_y][start_x] = 1;
	qs.push({ start_y,start_x });

	while (!qs.empty()) {
		int fire_size = q_fire.size();
		int s_size = qs.size();
		for (int i = 0;i < fire_size;i++) {
			int fy = q_fire.front().first;
			int fx = q_fire.front().second;
			q_fire.pop();

			for (int d = 0;d < 4;d++) {
				int nfy = fy + dy[d];
				int nfx = fx + dx[d];
				if (nfy < 0 || nfx < 0 || nfy >= h || nfx >= w) continue;
				if (arr[nfy][nfx] == '.' || arr[nfy][nfx] == '@') {
					arr[nfy][nfx] = '*';
					q_fire.push({ nfy,nfx });
				}
			}
		}
		for (int i = 0;i < s_size;i++) {
			int sy = qs.front().first;
			int sx = qs.front().second;
			qs.pop();
			if (sy == 0 || sy == h - 1 || sx == 0 || sx == w - 1) return visited[sy][sx];
			
			for (int d = 0;d < 4;d++) {
				int nsy = sy + dy[d];
				int nsx = sx + dx[d];
				if (nsy < 0 || nsx < 0 || nsy >= h || nsx >= w) continue;
				if (arr[nsy][nsx] == '.' && visited[nsy][nsx] == 0) {
					visited[nsy][nsx] = visited[sy][sx] + 1;
					qs.push({ nsy,nsx });
				}
			}
		}
	}

	return -1;
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;

	for (int tc = 0;tc < T;tc++) {
		int w, h;

		cin >> w >> h;
		queue<pair<int, int>>q_fire;
		for (int i = 0;i < h;i++) {
			string s;
			cin >> s;
			arr.push_back(s);
			for (int j = 0;j < w;j++) {
				if (s[j] == '@') {
					start_y = i;
					start_x = j;
				}
				else if (s[j] == '*') {
					q_fire.push({ i,j });
				}
			}
		}
		int ans = bfs(w, h, q_fire);
		if (ans == -1) {
			cout << "IMPOSSIBLE" << '\n';
		}
		else {
			cout << ans<<'\n';
		}
		arr.clear();

	}
	return 0;
}