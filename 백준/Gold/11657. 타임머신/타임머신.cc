#include <iostream>
#include <vector>
using namespace std;

#define INF 100000000

int N, M;


void bf(vector<vector<int>>& graph) {
	vector<long>distance(N + 1, INF);
	distance[1] = 0;
	bool loop = false;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			int now_node = graph[j][0];
			int next_node = graph[j][1];
			int cost = graph[j][2];
			if (distance[now_node] != INF && distance[next_node] > distance[now_node] + cost) {
				distance[next_node] = distance[now_node] + cost;
				if (i == N - 1) {
					loop = true;
					break;
				}
			}
		}
	}
	
	if (loop) {
		cout << -1;
		return;
	}
	else {
		for (int i = 2;i <= N;i++) {
			if (distance[i] == INF) distance[i] = -1;
			cout << distance[i] << '\n';
		}
	}

	return;
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;

	int A, B, C;
	vector<vector<int>>graph;
	for (int i = 0;i < M;i++) {
		cin >> A >> B >> C;
		graph.push_back({ A,B,C });
	}

	bf(graph);

	return 0;
}