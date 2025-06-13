#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

int R, C;
int dy[4] = { 0,0,1,-1 };
int dx[4] = { 1,-1,0,0 };
queue<pair<int, int>>ji;
queue<pair<int, int>>fire;


int bfs(vector<string>& graph) {
	vector<vector<int>>visited(R, vector<int>(C, 0));
	visited[ji.front().first][ji.front().second] = 1;
	bool escape = false;
	int lj, lf;
	while (!ji.empty()) {
		lf = fire.size();
		lj = ji.size();
		for (int i = 0;i < lf;i++) {
			int y = fire.front().first;
			int x = fire.front().second;
			fire.pop();
			for (int d = 0;d < 4;d++) {
				int ny = y + dy[d];
				int nx = x + dx[d];
				if (ny < 0 || nx < 0 || ny >= R || nx >= C) continue;
				if (graph[ny][nx] == '#' || graph[ny][nx] == 'F') continue;
				graph[ny][nx] = 'F';
				fire.push({ ny,nx });
			}

		}
		for (int i = 0;i < lj;i++) {
			int y = ji.front().first;
			int x = ji.front().second;
			if (y == 0 || x == 0 || y == R - 1 || x == C - 1) {
				//escape = true;
				return visited[y][x];
			}
			ji.pop();
			for (int d = 0;d < 4;d++) {
				int ny = y + dy[d];
				int nx = x + dx[d];
				if (ny < 0 || nx < 0 || ny >= R || nx >= C) continue;
				if (graph[ny][nx] == '#' || graph[ny][nx] == 'F') continue;
				if (visited[ny][nx] != 0) continue;
				visited[ny][nx] = visited[y][x] + 1;
				ji.push({ ny,nx });
			}
		}
	}

	return 0;
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> R >> C;

	vector<string>graph;
	
	string S;
	for (int i = 0;i < R;i++) {
		cin >> S;
		graph.push_back(S);
		for (int j = 0;j < C;j++) {
			if (S[j] == 'J') {
				ji.push({ i,j });
			}
			else if (S[j] == 'F') {
				fire.push({ i,j });
			}
		}
	}
	
	int ans = bfs(graph);
	if (ans == 0) {
		cout << "IMPOSSIBLE ";
	}
	else {
		cout << ans;
	}

	return 0;
}