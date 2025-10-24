#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#define MAX 101

int n;
int a, b;
int m;
int graph[MAX][MAX];
int visited[MAX];

int bfs() {
	int queue[MAX];
	int front = 0, rear = 0;
	visited[a] = 1;
	queue[rear++] = a;

	while (front < rear) {
		int now = queue[front++];

		for (int i = 1;i <= n;i++) {
			if (graph[now][i] == 1 && visited[i] == 0) {
				visited[i] = visited[now] + 1;
				queue[rear++] = i;
			}
		}
	}
	
	if (visited[b] == 0) return -1;
	return visited[b]-1;
}


int main() {
	scanf("%d", &n);
	scanf("%d %d", &a, &b);
	scanf("%d", &m);

	int child, parent;
	for (int i = 0;i < m;i++) {
		scanf("%d %d", &child, &parent);
		graph[child][parent] = 1;
		graph[parent][child] = 1;
	}

	printf("%d", bfs());

	return 0;
}