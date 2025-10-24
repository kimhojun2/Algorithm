#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#define MAX 101
int N, M;
int graph[MAX][MAX];
int visited[MAX][MAX];

int dy[4] = { 0,0,1,-1 };
int dx[4] = { 1,-1,0,0 };

void bfs() {
	int queue[MAX * MAX][2];
	int front = 0, rear = 0;
	queue[rear][0] = 0;
	queue[rear][1] = 0;
	rear++;
	visited[0][0] = 1;

	while (front < rear) {
		int y = queue[front][0];
		int x = queue[front][1];
		front++;

		for (int d = 0;d < 4;d++) {
			int ny = y + dy[d];
			int nx = x + dx[d];
			if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
			if (!graph[ny][nx] || visited[ny][nx])continue;

			visited[ny][nx] = visited[y][x] + 1;
			queue[rear][0] = ny;
			queue[rear][1] = nx;
			rear++;
		}
	}

}


int main() {

	scanf("%d %d", &N, &M);
	char line[MAX];

	for (int i = 0;i < N;i++) {
		scanf("%s", line);
		for (int j = 0;j < M;j++) {
			graph[i][j] = line[j] - '0';
		}
	}

	bfs();
	printf("%d", visited[N - 1][M - 1]);


	return 0;
}