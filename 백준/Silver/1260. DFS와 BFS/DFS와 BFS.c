#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX 1001
int N, M, V;
int graph[MAX][MAX];
int visited[MAX];

void dfs(int v) {
    visited[v] = 1;
    printf("%d ", v);
    for (int i = 1; i <= N; i++) {
        if (graph[v][i] == 1 && !visited[i]) dfs(i);
    }
}

void bfs(int v) {
    int queue[MAX];
    int front = 0, rear = 0;
    for (int i = 1; i <= N; i++) visited[i] = 0;
    visited[v] = 1;
    queue[rear++] = v;
    while (front < rear) {
        int now = queue[front++];
        printf("%d ", now);
        for (int i = 1; i <= N; i++) {
            if (graph[now][i] == 1 && !visited[i]) {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
}

int main() {
    scanf("%d %d %d", &N, &M, &V);
    for (int i = 0; i < M; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        graph[a][b] = graph[b][a] = 1;
    }
    for (int i = 1; i <= N; i++) visited[i] = 0;
    dfs(V);
    printf("\n");
    bfs(V);
    printf("\n");
    return 0;
}
