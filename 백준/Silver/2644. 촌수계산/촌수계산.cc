#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>>arr;
vector<int>visited;
int ans = -1;


void dfs(int start, int target, int depth) {
	visited[start] = 1;
	if (start == target) {
		ans = depth;
	}

	for (int i = 0;i < arr[start].size();i++) {
		int next = arr[start][i];
		if (!visited[next]) {
			dfs(next, target, depth + 1);
		}
	}

}



int main() {

	int N;
	cin >> N;

	int a, b;
	cin >> a >> b;
	int m;
	cin >> m;

	arr = vector<vector<int>>(N + 1);
	visited = vector<int>(N + 1, 0);

	for (int i = 0;i < m;i++) {
		int x, y;
		cin >> x >> y;
		arr[y].push_back(x);
		arr[x].push_back(y);
	}

	dfs(a,b,0);
	
	cout << ans;


	return 0;
}