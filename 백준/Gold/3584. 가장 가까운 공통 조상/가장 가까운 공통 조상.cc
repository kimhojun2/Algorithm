#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;

// set을 쓰는게 O(1)로 가능

int T;

// s1의 모든 조상들을 set에 저장
set<int> get_ancestors(map<int, vector<int>>& dic, int start) {
	set<int> ancestors;
	ancestors.insert(start);

	while (!dic[start].empty()) {
		start = dic[start][0]; // 부모는 한 명이므로 0번째
		ancestors.insert(start);
	}
	return ancestors;
}

// s2의 조상을 따라 올라가며 s1 조상과 만나는 최초 지점 반환
int find_lca(map<int, vector<int>>& dic, int start, set<int>& ancestors) {
	while (true) {
		if (ancestors.count(start)) return start;
		if (dic[start].empty()) break;
		start = dic[start][0]; // 부모로 이동
	}
	return -1; // 실패 시
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;

	for (int tc = 0; tc < T; tc++) {
		int N;
		cin >> N;

		map<int, vector<int>> dic;

		for (int i = 0; i < N - 1; i++) {
			int A, B;
			cin >> A >> B;
			dic[B].push_back(A); // B의 부모는 A
		}

		int s1, s2;
		cin >> s1 >> s2;

		set<int> ancestors = get_ancestors(dic, s1);
		int answer = find_lca(dic, s2, ancestors);

		cout << answer << '\n';
	}

	return 0;
}
