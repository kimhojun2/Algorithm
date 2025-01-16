import sys
from collections import deque

input = sys.stdin.readline


def bfs(start):
    q = deque()
    q.append(start)
    visited[start] = 0
    while q:
        now = q.popleft()
        for i in dic.get(now, {}):
            if visited[i] == -1:
                visited[i] = visited[now] + 1
                q.append(i)


N, M, R = map(int, input().split())
visited = [-1] * (N + 1)
dic = {}
for i in range(M):
    s, e = map(int, input().split())
    if s not in dic:
        dic[s] = [e]
    else:
        dic[s].append(e)
    if e not in dic:
        dic[e] = [s]
    else:
        dic[e].append(s)

bfs(R)

for i in range(1, N + 1):
    print(visited[i])

