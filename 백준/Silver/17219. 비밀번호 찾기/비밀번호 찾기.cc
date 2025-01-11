#include <iostream>
#include <map>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, M;
	map<string, string> m;
	string site, password;
	
	cin >> N >> M;

	for (int i = 0;i < N;i++) {
		cin >> site >> password;
		m[site] = password;
	}

	for (int i = 0;i < M;i++) {
		cin >> site;
		cout << m[site] << '\n';
	}

	return 0;
}