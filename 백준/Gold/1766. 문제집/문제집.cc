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

	for (int i = 0;i < M;i++) {
		int A, B;
		cin >> A >> B;
		adj[A].push_back(B);
		indgree[B]++;
	}

	priority_queue<int, vector<int>, greater<int>>pq;
	for (int i = 1;i <= N;i++) {
		if (indgree[i] == 0)pq.push(i);
	}

	while (!pq.empty()) {
		int curr = pq.top();
		pq.pop();

		cout << curr << " ";

		for (int i = 0;i < adj[curr].size();i++) {
			int nxt = adj[curr][i];
			if (--indgree[nxt] == 0) {
				pq.push(nxt);
			}
		}

	}



	return 0;
}