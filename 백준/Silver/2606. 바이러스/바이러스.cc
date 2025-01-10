#include <iostream>
#include <queue>

#define MAX 101

using namespace std;

int N = 0, M= 0;
int G[MAX][MAX] = { 0, };

queue <int> Q;
bool visited[MAX] = { 0, };

int cnt = 0;

void BFS(int s) {
	Q.push(s);
	visited[s] = true;

	while (!Q.empty()) {
		s = Q.front();
		Q.pop();

		for (int i = 1;i <= N;i++) {
			if (G[s][i] == 1 && visited[i] == 0) {
				Q.push(i);
				visited[i] = true;
				cnt++;
			}
		}
	}

}



int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0;i < M;i++) {
		int start =0, end = 0;
		cin >> start >> end;
		G[start][end] = 1;
		G[end][start] = 1;
	}
	BFS(1);
	cout << cnt << endl;
	

	return 0;
}