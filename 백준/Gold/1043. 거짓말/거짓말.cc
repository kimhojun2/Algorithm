#include <iostream>
#include <queue>
#include <vector>
using namespace std;


int N, M, L;
int ans = 0;


void bfs(vector<int> &liar, vector<vector<int>>& lst, vector<vector<int>>& party) {
	queue<int>q;
	vector<bool>visited(M + 1, false);
	for (int i = 0;i < L;i++) {
		q.push(liar[i]);
	}

	while (!q.empty()) {
		int now = q.front(); q.pop();
		for (int i = 0;i < lst[now].size();i++) {
			int next = lst[now][i];
			if (!visited[next]) {
				visited[next] = true;
				for (int j = 0;j < party[next].size();j++) {
					if (now != party[next][j]) {
						q.push(party[next][j]);
					}
				}
			}
		}
	}

	for (int i = 1;i <= M;i++) {
		if (!visited[i]) ans++;
	}
	cout << ans;

}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;

	vector<int>liar;
	cin >> L;

	if (L == 0) {
		cout << M;
		return 0;
	}

	for (int i = 0;i < L;i++) {
		int p;
		cin >> p;
		liar.push_back(p);
	}

	vector<vector<int>>lst(N+1);
	vector<vector<int>>party(M + 1);
	for (int i = 1;i <= M;i++) {
		int num;
		cin >> num;
		for (int j = 0;j < num;j++) {
			int now;
			cin >> now;
			lst[now].push_back(i);
			party[i].push_back(now);
		}
	}

	bfs(liar, lst, party);

	return 0;
}