#include <iostream>
#include <vector>
#include <algorithm>
#define MAX_SIZE 101

using namespace std;

int arr[MAX_SIZE] = { 0, };
int N;
vector<int> check;


void dfs(vector<int> &result,int (& visited)[MAX_SIZE], int start, int now) {
	visited[now] = 1;
	result.push_back(now);

	int next = arr[now];
	if (start == next) {
		check.insert(check.end(), result.begin(), result.end());
		return;
	}
	
	if (!visited[next]) {
		visited[next] = 1;
		dfs(result,visited, start, next);
	}

}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N;
	for (int i=1;i <= N;i++) {
		cin >> arr[i];
	}

	for (int i = 1;i <= N;i++) {
		if (find(check.begin(),check.end(),i)==check.end()) {
			int visited[MAX_SIZE] = { 0, };
			vector<int> result;
			dfs(result, visited, i, i);
		}
	}

	sort(check.begin(), check.end());

	cout << check.size() << '\n';
	for (int i : check) {
		cout << i << '\n';
	}

	
	return 0;
}