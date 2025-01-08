from collections import deque


def BFS(arr, s, N):
    queue = deque()
    visited[s] = 1
    queue.append(s)
    while queue:
        now = queue.popleft()
        for next in range(N+1):
            if not visited[next] and arr[now][next] == 1:
                visited[next] = 1
                queue.append(next)





N, M = map(int, input().split())
arr = [[0]*(N+1)for _ in range(N+1)]
for m in range(M):
    u1, u2 = map(int, input().split())
    arr[u1][u2] = 1
    arr[u2][u1] = 1

visited = [0]*(N+1)
visited[0] = 1
cnt = 0
for n in range(N+1):
    if not visited[n]:
        BFS(arr, n, N)
        cnt += 1
print(cnt)

