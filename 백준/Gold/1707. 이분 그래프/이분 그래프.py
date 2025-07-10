from collections import deque
import sys
input = sys.stdin.readline


def check():
    visited = [-1]*(V+1)
    q = deque()
    for i in range(1,V+1):
        if visited[i] != -1: continue

        q.append(i)
        visited[i] = 0

        while q:
            now = q.popleft()
            for next_node in graph[now]:
                if visited[next_node] == -1:
                    visited[next_node] = 1 - visited[now]
                    q.append(next_node)

                elif visited[now] == visited[next_node]:
                    return False

    return True


K = int(input())

for tc in range(K):
    V, E = map(int, input().split())

    graph = [[] for _ in range(V+1)]
    for e in range(E):
        u,v = map(int, input().split())
        graph[u].append(v)
        graph[v].append(u)

    if check():
        print('YES')
    else:
        print("NO")