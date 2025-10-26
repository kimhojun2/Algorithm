#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

#define MAXSIZE 25

int N;
int graph[MAXSIZE][MAXSIZE];
//int visited[MAXSIZE][MAXSIZE];
int dy[4] = { 0,0,1,-1 };
int dx[4] = { 1,-1,0,0 };

int bfs(int sy, int sx) {
	int queue[MAXSIZE*MAXSIZE][2];
	int front = 0, rear = 0;
	queue[rear][0] = sy;
	queue[rear][1] = sx;
	rear++;
	//visited[sy][sx] = 1;

	int cnt = 1;
	while (front < rear) {
		int y = queue[front][0];
		int x = queue[front][1];
		graph[y][x] = 0;
		front++;
		for (int d = 0;d < 4;d++) {
			int ny = dy[d] + y;
			int nx = dx[d] + x;
			if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
			//if (graph[ny][nx] == 0 || visited[ny][nx] == 1) continue;
			if (graph[ny][nx] == 0) continue;
			graph[ny][nx] = 0;
			cnt++;
			queue[rear][0] = ny;
			queue[rear][1] = nx;
			rear++;
		}
	}

	return cnt;
}

int main(){
	scanf("%d", &N);

	char line[26];
	for (int i = 0;i < N;i++) {
		scanf("%s", line);
		for (int j = 0;j < N;j++) {
			graph[i][j] = line[j] - '0';
		}
	}

	int answer[MAXSIZE * MAXSIZE] = { 0, };
	int idx = 0;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			if (graph[i][j] == 1) {
				answer[idx++] = bfs(i, j);
			}
		}
	}
	for (int i = 0;i < idx - 1;i++) {
		for (int j = i + 1;j < idx;j++) {
			if (answer[i] > answer[j]) {
				int t = answer[i]; answer[i] = answer[j]; answer[j] = t;
			}
		}
	}
	printf("%d\n", idx);

	for (int i = 0;i < idx;i++) {
		printf("%d\n", answer[i]);
	}

	return 0;
}