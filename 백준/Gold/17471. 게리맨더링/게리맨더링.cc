#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N;
int people[11] = { 0, };
vector<int> arr[11];
bool selected[11];
int answer = 1000;

bool check() {
	vector<int>A, B;
	for (int i = 1; i <= N; i++)
	{
		if (selected[i]) A.push_back(i);
		else B.push_back(i);
	}


	vector<bool> visited_A(N + 1, false);
	queue<int> q_A;
	visited_A[A[0]] = true;
	q_A.push(A[0]);

	int cnt_A = 1;
	while (!q_A.empty()){
		int cur = q_A.front();
		q_A.pop();

		for (int next : arr[cur])
		{
			if (selected[next] != true || visited_A[next]) continue;

			visited_A[next] = true;
			cnt_A++;
			q_A.push(next);
		}
	}

	if (cnt_A != A.size()) return false;
	
	
	vector<bool> visited_B(N + 1, false);
	queue<int> q_B;
	visited_B[B[0]] = true;
	q_B.push(B[0]);

	int cnt_B = 1;
	while (!q_B.empty()){
		int cur = q_B.front();
		q_B.pop();

		for (int next : arr[cur])
		{
			if (selected[next] != false || visited_B[next]) continue;

			visited_B[next] = true;
			cnt_B++;
			q_B.push(next);
		}
	}

	if (cnt_B != B.size()) return false;

	return true;
}


void make(int idx, int level) {
	if (level > 0 && level < N) {
		if (check()) {
			int a = 0, b = 0;

			for (int i = 1; i <= N; i++)
			{
				if (selected[i]) a += people[i];
				else b += people[i];
			}

			answer = min(answer, abs(a - b));
		}
	}
	for (int i = idx;i <= N;i++) {
		if (!selected[i]) {
			selected[i] = true;
			make(idx + 1, level + 1);
			selected[i] = false;
		}
	}
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N;

	for (int i = 1;i <= N;i++) {
		cin >> people[i];
	}
	for (int i = 1;i <= N;i++) {
		int n;
		cin >> n;
		for (int j = 0;j < n;j++) {
			int connect;
			cin >> connect;
			arr[i].push_back(connect);
			arr[connect].push_back(i);
		}
	}

	make(1, 0);

	if (answer == 1000) answer = -1;

	cout << answer;

	return 0;
}