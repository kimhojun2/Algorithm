#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

# define MAXSIZE 31

int L, R, C;
int sz, sy, sx, ez, ey, ex;
char graph[MAXSIZE][MAXSIZE][MAXSIZE];
int visited[MAXSIZE][MAXSIZE][MAXSIZE];
char line[MAXSIZE];

int dz[6] = { 0,0,0,0,1,-1 };
int dy[6] = { 0,0,1,-1,0,0 };
int dx[6] = { 1,-1,0,0,0,0 };


void clean() {
	for (int k = 0;k < L;k++) {
		for (int i = 0;i < R;i++) {
			for (int j = 0;j < C;j++) {
				visited[k][i][j] = 0;
			}
		}
	}
}


int bfs() {
	int queue[MAXSIZE * MAXSIZE * MAXSIZE][3];
	int front = 0, rear = 0;
	queue[rear][0] = sz, queue[rear][1] = sy, queue[rear][2] = sx;
	visited[sz][sy][sx] = 1;
	rear++;

	while (front < rear) {
		int z = queue[front][0];
		int y = queue[front][1];
		int x = queue[front][2];
		front++;

		if (z == ez && y == ey && x == ex) return visited[z][y][x];

		for (int d = 0;d < 6;d++) {
			int nz = z + dz[d];
			int ny = y + dy[d];
			int nx = x + dx[d];
			
			if (nz < 0 || ny < 0 || nx < 0 || nz >= L || ny >= R || nx >= C)continue;
			if (graph[nz][ny][nx] == '#' || visited[nz][ny][nx] != 0) continue;

			visited[nz][ny][nx] = visited[z][y][x] + 1;
			queue[rear][0] = nz, queue[rear][1] = ny, queue[rear][2] = nx;
			rear++;
		}
	}

	return 0;
}


int main() {
		
	while (1) {
		scanf("%d %d %d", &L, &R, &C);
		if (L == 0 && R == 0 && C == 0) break;
		
		clean();

		for (int k = 0;k < L;k++) {
			for (int i = 0;i < R;i++) {
				scanf("%s", line);
				for (int j = 0;j < C;j++) {
					if (line[j] == 'S') {
						sz = k, sy = i;sx = j;
					}
					else if (line[j] == 'E') {
						ez = k, ey = i, ex = j;
					}
					graph[k][i][j] = line[j];
				}
			}
		}

		int ans = bfs();

		if (!ans) {
			printf("Trapped!\n");
		}
		else {
			printf("Escaped in %d minute(s).\n", ans-1);
		}
	}


	return 0;
}