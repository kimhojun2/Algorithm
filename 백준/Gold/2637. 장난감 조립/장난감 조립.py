from collections import deque, defaultdict
import sys
input = sys.stdin.readline

N = int(input())
M = int(input())

graph = defaultdict(list)
indegree = [0] * (N + 1)
need = [[0] * (N + 1) for _ in range(N + 1)]

for _ in range(M):
    X, Y, K = map(int, input().split())
    graph[Y].append((X, K))
    indegree[X] += 1

q = deque()

for i in range(1, N + 1):
    if indegree[i] == 0:
        q.append(i)
        need[i][i] = 1

while q:
    now = q.popleft()
    for next, cnt in graph[now]:
        for i in range(1, N + 1):
            need[next][i] += need[now][i] * cnt
        indegree[next] -= 1
        if indegree[next] == 0:
            q.append(next)

for i in range(1, N + 1):
    if need[N][i] > 0:
        print(i, need[N][i])
