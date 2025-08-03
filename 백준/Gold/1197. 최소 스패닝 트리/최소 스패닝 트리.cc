#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int V, E;
int parents[10001];
int ans = 0;

int get_parent(int num) {
	if (num == parents[num]) return num;
	return parents[num] = get_parent(parents[num]);
}


void union_parent(int a, int b) {
	a = get_parent(a);
	b = get_parent(b);

	if (a != b) {
		parents[a] = b;
	}
}


bool find_parent(int a, int b) {
	a = get_parent(a);
	b = get_parent(b);
	if (a == b) return true;
	else return false;

}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> V >> E;
	vector<pair<int, pair<int, int>>>edges(E);

	for (int i = 0;i < E;i++) {
		int A, B, C;
		cin >> A >> B >> C;
		edges[i] = { C,{A,B} };
	}
	for (int i = 1;i <= V;i++) {
		parents[i] = i;
	}
	sort(edges.begin(), edges.end());

	for (int i = 0;i < E;i++) {
		int cost = edges[i].first;
		int a = edges[i].second.first;
		int b = edges[i].second.second;
		if (!find_parent(a, b)) {
			ans += cost;
			union_parent(a, b);
		}
	}

	cout << ans;

	return 0;
}