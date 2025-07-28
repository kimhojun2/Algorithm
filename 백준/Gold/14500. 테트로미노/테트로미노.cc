#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
int arr[501][501] = { 0, };
int max_point = 0;

vector<vector<vector<int>>> dy = {
	//일자
	{{0,0,0,0},{0,1,2,3}},
	//정사각형
	{{0,0,1,1}},
	//ㄴ자
	{{0,1,2,2},{0,0,0,1},{0,0,1,2},{0,1,1,1},{0,1,2,2},{0,1,1,1},{0,0,1,2},{0,0,0,1}},
	//ㄹ자
	{{0,1,1,2},{0,0,-1,-1},{0,1,1,2},{0,0,1,1}},
	//ㅗ자
	{{0,0,0,1},{0,0,-1,1},{0,0,0,-1},{0,1,1,2}}
};

vector<vector<vector<int>>> dx = {
	//일자
	{{0,1,2,3},{0,0,0,0}},
	//정사각형
	{{0,1,0,1}},
	//ㄴ자
	{{0,0,0,1},{0,1,2,0},{0,1,1,1},{0,0,-1,-2},{0,0,0,-1},{0,0,1,2},{0,1,0,0},{0,1,2,2}},
	//ㄹ자
	{{0,0,1,1},{0,1,1,2},{0,0,-1,-1},{0,1,1,2}},
	//ㅗ자
	{{0,1,2,1},{0,1,1,1},{0,1,2,1},{0,0,1,0}}
};

void check_point(int y, int x) {
	for (int i = 0;i < 5;i++) {
		for (int j = 0;j < dy[i].size();j++) {
			int now_point = 0;
			for (int d = 0;d < 4;d++) {
				int ny = y + dy[i][j][d];
				int nx = x + dx[i][j][d];
				if (ny < 0 || nx < 0 || ny >= N || nx >= M) {
					now_point = 0;
					break;
				}
				now_point += arr[ny][nx];
			}
			max_point = max(max_point, now_point);
		}
	}

}




int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;

	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			cin >> arr[i][j];
		}
	}

	for (int y = 0;y < N;y++) {
		for (int x = 0;x < M;x++) {
			check_point(y, x);
		}
	}

	cout << max_point;



	return 0;
}