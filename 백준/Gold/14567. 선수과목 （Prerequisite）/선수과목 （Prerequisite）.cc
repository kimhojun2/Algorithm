#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, M;
	cin >> N >> M;

	vector<vector<int>>adj(N + 1);
	vector<int>indgree(N + 1, 0);
	vector<int>ans(N + 1, 0);
	for (int i = 0;i < M;i++) {
		int A, B;
		cin >> A >> B;
		adj[A].push_back(B);
		indgree[B]++;
	}

	queue<pair<int,int>>q;
	for (int i = 1;i <= N;i++) {
		if (indgree[i] == 0)q.push({i,1});
	}

	while (!q.empty()) {
		int curr = q.front().first;
		int t = q.front().second;
		q.pop();
		ans[curr] = t;
		for (int i = 0;i < adj[curr].size();i++) {
			int nxt = adj[curr][i];
			if (--indgree[nxt] == 0) {
				q.push({ nxt,t+1 });
			}
		}
	}

	for (int i = 1;i <= N;i++) cout << ans[i] << " ";


	return 0;
}