#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N, M;
int dist[50001];
vector<pair<int, int>> graph[50001];

void dijkstra(int start) {
	for (int i = 1;i <= N;i++) {
		dist[i] = 1e9;
	}
	priority_queue<pair<int, int>>pq;
	pq.push({ 0,start });
	dist[start] = 0;
	while (!pq.empty()) {
		int cost = -pq.top().first;
		int now = pq.top().second;
		pq.pop();

		if (dist[now] < cost) continue;

		for (int i = 0;i < graph[now].size();i++) {
			int next = graph[now][i].first;
			int new_cost = graph[now][i].second + cost;
			if (dist[next] > new_cost) {
				dist[next] = new_cost;
				pq.push({ -new_cost,next });
			}
		}
	}
}



int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> N >> M;

	for (int i = 0;i < M;i++) {
		int A, B, C;
		cin >> A >> B >> C;
		graph[A].push_back({ B,C });
		graph[B].push_back({ A,C });
	}

	dijkstra(1);
	cout << dist[N];

	return 0;
}