#include <iostream>
using namespace std;

int arr[101][101] = { 0, };

int main() {
	int cnt = 0;
	for (int i = 0;i < 4;i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		for (int y = y1;y < y2;y++) {
			for (int x = x1;x < x2;x++) {
				if (arr[y][x] == 0) {
					arr[y][x] = 1;
					cnt += 1;
				}
			}
		}
	}
	cout << cnt;

	return 0;
}