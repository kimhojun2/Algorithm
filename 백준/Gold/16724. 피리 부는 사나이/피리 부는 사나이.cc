#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int N, M;

char arr[1000][1000];
int visited[1000][1000];
int ans = 0;
int cp = 1;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			cin >> arr[i][j];
		}
	}
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (visited[i][j] == 0) {
                int curr_i = i, curr_j = j;
                while (visited[curr_i][curr_j] == 0) {
                    visited[curr_i][curr_j] = cp;

                    char dir = arr[curr_i][curr_j];
                    if (dir == 'U') curr_i--;
                    else if (dir == 'D') curr_i++;
                    else if (dir == 'R') curr_j++;
                    else curr_j--;

                }
                if (visited[curr_i][curr_j] == cp) ans++;
                cp++;
            }
        }
    }

    cout << ans;

	return 0;
}