#include <iostream>
#include <vector>
#include <map>
#include <deque>
using namespace std;

int N, M;
map<int, int> ladder;
map<int, int> snake;
deque<int> space;
int visited[101] = { -1, };

int snake_game() {
	space.push_back(1);
	visited[1] = 0;
	
	while (!space.empty()) {
		int now = space.front();
		space.pop_front();
		if (now == 100) {
			return visited[100];
		}

		for (int i = 1;i <= 6;i++) {
			int next = now + i;
			if (next > 100) {
				continue;
			}


			if (ladder.count(next)) {
				next = ladder[next];
			}
			else if (snake.count(next)) {
				next = snake[next];
			}
			if (visited[next] == 0 || visited[next] > visited[now] + 1) {
				if (next == 100) {
					visited[next] = visited[now] + 1;
					space.push_front(next);
					break;
				}
				visited[next] = visited[now] + 1;
				space.push_back(next);
			}
		}
	}
}



int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N >> M;
	for (int i = 0;i < N;i++) {
		int x,y;
		cin >> x >> y;
		ladder[x] = y;
		
	}
	for (int i = 0;i < M;i++) {
		int u, v;
		cin >> u >> v;
		snake[u] = v;
	}
	int ans = snake_game();
	cout << ans;

	return 0;
}