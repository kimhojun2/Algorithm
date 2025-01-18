#include <iostream>
#include <queue>
#include <algorithm>

#define MAX 200001

using namespace std;

int N, K;
int visited[MAX] = { 0, };

void bfs() {
	queue<int> q;
	q.push(N);
	visited[N] = 1;
	while (!q.empty()) {
		int now = q.front();
		q.pop();

		if (now == K) {
			return;
		}

		int next;
		for (int i = 1;i <= 3;i++) {
			switch (i) {
			case 1:
				next = now * 2;
				break;
			case 2:
				next = now + 1;
				break;
			case 3:
				next = now - 1;
				break;
			}
			if (0 <= next && next < MAX && visited[next]==0) {
				visited[next] = visited[now] + 1;
				q.push(next);
			}
		}

		
	}
	
}


int main() {

	cin >> N >> K;

	bfs();
	cout << visited[K] - 1;

	return 0;
}