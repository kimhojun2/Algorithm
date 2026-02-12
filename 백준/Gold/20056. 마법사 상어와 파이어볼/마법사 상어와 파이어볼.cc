#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int N, M, K;


struct Fireball {
	int y, x, m, s, d;
};


vector<int> arr[50][50];

queue<Fireball>q;
vector<Fireball>lst;

int dy[] = { -1,-1,0,1,1,1,0,-1 };
int dx[] = { 0,1,1,1,0,-1,-1,-1 };


void func_moving() {
	int L = q.size();
	for (int i = 0;i < L;i++) {
		Fireball curr = q.front();
		q.pop();
		curr.y = (curr.y + dy[curr.d] * (curr.s % N) + N) % N;
		curr.x = (curr.x + dx[curr.d] * (curr.s % N) + N) % N;
		lst.push_back(curr);
		arr[curr.y][curr.x].push_back(i);
	}

	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			if (arr[i][j].empty()) continue;
			if (arr[i][j].size() == 1) {
				q.push(lst[arr[i][j][0]]);
			}
			else {
				int total_m = 0;
				int total_s = 0;
				int nxt_d = lst[arr[i][j][0]].d % 2;
				bool same = true;

				for (int k = 0; k < arr[i][j].size(); k++) {
					int idx = arr[i][j][k];
					total_m += lst[idx].m;
					total_s += lst[idx].s;
					if (lst[idx].d % 2 != nxt_d) same = false;
				}

				int nxt_m = total_m / 5;
				if (nxt_m == 0) {
					arr[i][j].clear();
					continue;
				}

				int nxt_s = total_s / (int)arr[i][j].size();
				if (same) {
					for (int k = 0;k < 8;k += 2) {
						q.push({ i,j,nxt_m,nxt_s,k });
					}
				}
				else {
					for (int k = 1;k < 8;k += 2) {
						q.push({ i,j,nxt_m,nxt_s,k });
					}
				}
			}
			arr[i][j].clear();
		}
	}

	lst.clear();
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M >> K;
	for (int i = 0;i < M;i++) {
		int r, c, m, s, d;
		cin >> r >> c >> m >> s >> d;
		Fireball new_fb = { r - 1,c - 1,m,s,d };
		q.push(new_fb);
	}

	while (K--) {
		func_moving();
	}

	long long total_ans = 0;
	while (!q.empty()) {
		total_ans += q.front().m;
		q.pop();
	}
	cout << total_ans;

	return 0;
}