from collections import deque

def bfs(start):
    visited = [0] * (N + 1)
    visited[start] = 1
    q = deque()
    q.append(start)

    while q:
        now = q.popleft()
        for i in range(1, N + 1):
            if not visited[i] and graph[now - 1][i - 1] == 1:
                visited[i] = 1
                q.append(i)

    return visited

N = int(input())
M = int(input())
graph = [list(map(int, input().split())) for _ in range(N)]
plan = list(map(int, input().split()))

visited = bfs(plan[0])

for city in plan:
    if not visited[city]:
        print('NO')
        break
else:
    print('YES')
