#include <iostream>
#include <vector>
using namespace std;

int N;
int root;
int del;
int answer = 0;
struct tree
{
	vector<int>child;
};

void check(int start, vector<tree>nodes) {
	if (nodes[start].child.empty() || (nodes[start].child.size() == 1 && nodes[start].child[0] == del)) {
		answer++;
		return;
	}
	else {
		for (int i = 0;i < nodes[start].child.size();i++) {
			if (nodes[start].child[i] == del) continue;
			check(nodes[start].child[i], nodes);
		}
	}

	return;
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	vector<tree>nodes(N);
	for (int i = 0;i < N;i++) {
		int parent;
		cin >> parent;
		if (parent == -1) {
			root = i;
		}
		else {
			nodes[parent].child.push_back(i);
		}
	}

	cin >> del;

	if (root != del) {
		check(root, nodes);
	}

	cout << answer;

	return 0;
}