#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<int,string>a,pair<int,string>b) {
	if (a.first == b.first) {
		if (a.second.length() == b.second.length()) {
			return a.second < b.second;
		}
		else {
			return a.second.length() > b.second.length();
		}
	}
	else {
		return a.first > b.first;
	}
}

int main() {
	int N, M;
	cin >> N >> M;

	map<string, int> dic;
	for (int i = 0;i < N;i++) {
		string word;
		cin >> word;
		if (word.length() < M) {
			continue;
		}
		dic[word]++;
	}
	vector<pair<int, string>>book;
	for (auto i : dic) {
		book.push_back({ i.second,i.first });
	}

	sort(book.begin(), book.end(), compare);

	for (auto i : book) {
		cout << i.second << '\n';
	}

	

	return 0;
}