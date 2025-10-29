#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define MAXSIZE 50

int N, M;
int graph[MAXSIZE][MAXSIZE];
int visited[MAXSIZE][MAXSIZE];
int dy[8] = { -1,-1,0,1,1,1,0,-1};
int dx[8] = { 0,1,1,1,0,-1,-1,-1};

void clean() {
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			graph[i][j] = 0;
			visited[i][j] = 0;
		}
	}
}


void bfs(int i, int j) {
	int queue[MAXSIZE * MAXSIZE][2];
	int front = 0, rear = 0;
	queue[rear][0] = i;
	queue[rear][1] = j;
	rear++;
	visited[i][j] = 1;

	while (front < rear) {
		int y = queue[front][0];
		int x = queue[front][1];
		front++;

		for (int d = 0;d < 8;d++) {
			int ny = y + dy[d];
			int nx = x + dx[d];
			if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
			if (!graph[ny][nx] || visited[ny][nx]) continue;
			visited[ny][nx] = 1;
			queue[rear][0] = ny;
			queue[rear][1] = nx;
			rear++;
		}
	}

}


int main() {
	
	while (1) {
		scanf("%d %d", &M, &N);
		if (N == 0 && M == 0) break;
		clean();
		int answer = 0;

		for (int i = 0;i < N;i++) {
			for (int j = 0;j < M;j++) {
				scanf("%d", &graph[i][j]);
			}
		}

		for (int i = 0;i < N;i++) {
			for (int j = 0;j < M;j++) {
				if (graph[i][j] == 1 && visited[i][j] == 0) {
					answer++;
					bfs(i,j);
				}
			}
		}

		printf("%d\n", answer);

	}
	


	return 0;
}