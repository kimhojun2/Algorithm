#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

int M, N, K;
int arr[100][100] = { 0, };
int dy[] = { 0,0,1,-1 };
int dx[] = { 1,-1,0,0 };
vector<int> answer_list;

void bfs(int i, int j) {
	queue<pair<int, int>>q;
	q.push({ i,j });
	arr[i][j] = 1;
	int cnt = 1;
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int d = 0;d < 4;d++) {
			int ny = y + dy[d];
			int nx = x + dx[d];
			if (ny < 0 || nx < 0 || ny >= M || nx >= N) continue;
			if (arr[ny][nx] == 0) {
				cnt++;
				arr[ny][nx] = 1;
				q.push({ ny,nx });
			}
		}
	}
	answer_list.push_back(cnt);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> M >> N >> K;
	for (int i = 0;i < K;i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		for (int y = y1;y < y2;y++) {
			for (int x = x1;x < x2; x++) {
				arr[y][x] = 1;
			}

		}
	}
	int answer = 0;
	for (int i = 0;i < M;i++) {
		for (int j = 0;j < N;j++) {
			if (arr[i][j] == 0) {
				bfs(i, j);
				answer++;
			}
		}
	}
	
	sort(answer_list.begin(), answer_list.end());
	
	cout << answer<<'\n';
	for (int ans : answer_list) {
		cout << ans << " ";
	}

	return 0;
}