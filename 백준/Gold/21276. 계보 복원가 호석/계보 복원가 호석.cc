#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N,M;
map<string, int>idx;
map<int, string>names;
map<int, vector<int>>graph;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	vector<int>indgree(N);
	vector<string>nn;

	for (int i = 0;i < N;i++) {
		string name;
		cin >> name;
		nn.push_back(name);
	}

	sort(nn.begin(), nn.end());

	for (int i = 0;i < N;i++) {
		idx[nn[i]] = i;
		names[i] = nn[i];
	}
	cin >> M;

	for (int i = 0;i < M;i++) {
		string parent, child;
		cin >> child >> parent;
		graph[idx[parent]].push_back(idx[child]);
		indgree[idx[child]]++;
	}

	queue<int>q;
	int cnt = 0;
	vector<string>clan;
	for (int i = 0;i < N;i++) {
		if (indgree[i] == 0) {
			cnt++;
			clan.push_back(names[i]);
			q.push(i);
		}
	}

	map<int, vector<int>> children;

	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (int i = 0;i < graph[now].size();i++) {
			indgree[graph[now][i]]--;
			if (indgree[graph[now][i]] == 0) {
				q.push(graph[now][i]);
				children[now].push_back(graph[now][i]);
			}
		}
	}

	cout << cnt << '\n';
	for (int i = 0;i < clan.size();i++) {
		cout << clan[i] << " ";
	}
	cout << '\n';
	for (int i = 0; i < N; i++) {
		vector<int>& c = children[i];
		sort(c.begin(), c.end());
		cout << names[i] << ' ' << c.size();
		for (int child : c) {
			cout << ' ' << names[child];
		}
		cout << '\n';
	}
	
	return 0;
}