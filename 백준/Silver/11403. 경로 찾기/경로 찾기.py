N = int(input())
arr = [list(map(int, input().split())) for _ in range(N)]
visited = [0] * N

def dfs(x):
    for i in range(N):
        if arr[x][i] == 1 and visited[i] == 0:
            visited[i] = 1
            dfs(i)

for i in range(N):
    dfs(i)
    for j in range(N):
        if visited[j] == 1:
            arr[i][j] = 1
    visited = [0] * N

for row in range(N):
    print(*arr[row])
#   0   1   2   0