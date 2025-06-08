#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int F, S, G, U, D;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> F >> S >> G >> U >> D;

	vector<int> visited(F + 1, 0);
	queue<int>q;
	q.push(S);
	visited[S] = 1;

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		if (now == G) break;

		if (now + U <= F) {
			if (visited[now + U] == 0 || visited[now + U] > visited[now] + 1) {
				visited[now + U] = visited[now] + 1;
				q.push(now + U);
			}
		}

		if (now - D >= 1) {
			if (visited[now - D] == 0 || visited[now - D] > visited[now] + 1) {
				visited[now - D] = visited[now] + 1;
				q.push(now - D);
			}
		}

	}

	if (visited[G] == 0) cout << "use the stairs";
	else cout << visited[G] - 1;


	return 0;
}