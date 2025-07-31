#include <iostream>
#include <vector>
using namespace std;

int N;

void hanoi(int n, int start, int via, int end) {
	if (n == 1) {
		cout << start << " " << end << '\n';
		return;
	}

	hanoi(n - 1, start, end, via);
	cout << start << " " << end << '\n';
	hanoi(n - 1, via, start, end);

}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	cout << (1 << N) - 1 << '\n';
	hanoi(N, 1, 2, 3);


	return 0;
}