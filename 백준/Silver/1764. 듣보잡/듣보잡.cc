#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <algorithm>


using namespace std;

int main() {
	int N, M;
	cin >> N >> M;

	set<string> s1;
	vector<string> result;
	string name;

	for (int i = 0;i < N;i++) {
		cin >> name;
		s1.insert(name);
	}
	for (int i = 0;i < M;i++) {
		cin >> name;
		if (s1.find(name)!= s1.end()) {
			result.push_back(name);
		}
	}

	sort(result.begin(), result.end());
	cout << result.size() << '\n';
	for (const auto& person : result) {
		cout << person << '\n';
	}
	return 0;
}