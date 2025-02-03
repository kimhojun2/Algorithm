#include<iostream>
#include<string>
#include<queue>
using namespace std;

string s, t;
int ans;
void func() {
	queue<string>q;
	q.push(t);
	while (!q.empty()) {
		string now = q.front();
		q.pop();
		if (now == s) {
			ans = 1;
			return;
		}

		if (now[now.length() - 1] == 'A') {
			string temp = now.substr(0, now.length() - 1);
			q.push(temp);
		}
		if (now[0] == 'B') {
			string temp = "";
			for (int i = now.length() - 1; i > 0; i--) {
				temp += now[i];
			}
			q.push(temp);
		}
	}

}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
	cin >> s >> t;
	func();
	cout << ans;
	return 0;
}