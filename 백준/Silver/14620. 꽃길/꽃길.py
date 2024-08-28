N = int(input())
arr = [list(map(int, input().split())) for _ in range(N)]
visited = [[0]*N for _ in range(N)]
ans = float('inf')
di = [0,0,1,-1]
dj = [1,-1,0,0]


def dfs(level, total, y, x):
    global ans
    if level == 3:
        ans = min(ans, total)
        return

    for i in range(1,N-1):
        for j in range(1, N-1):
            if visited[i][j]:
                continue

            now = arr[i][j]
            error = False
            for d in range(4):
                ni, nj = i + di[d], j + dj[d]
                if 0 <= ni < N and 0 <= nj < N and not visited[ni][nj]:
                    now += arr[ni][nj]

                else:
                    error = True
                    break

            if not error:
                visited[i][j] = 1
                visited[i + 1][j] = 1
                visited[i - 1][j] = 1
                visited[i][j - 1] = 1
                visited[i][j + 1] = 1
                dfs(level+1, total + now, i, j)
                visited[i][j] = 0
                visited[i + 1][j] = 0
                visited[i - 1][j] = 0
                visited[i][j - 1] = 0
                visited[i][j + 1] = 0



for i in range(1,N-1):
    for j in range(1, N-1):
        now = arr[i][j]
        error = False
        for d in range(4):
            ni, nj = i + di[d], j + dj[d]
            if 0<= ni < N and 0<= nj < N:
                now += arr[ni][nj]

            else:
                error = True
                break

        if not error:
            visited[i][j] = 1
            visited[i+1][j] = 1
            visited[i-1][j] = 1
            visited[i][j-1] = 1
            visited[i][j+1] = 1
            dfs(1, now, i, j)
            visited[i][j] = 0
            visited[i+1][j] = 0
            visited[i-1][j] = 0
            visited[i][j-1] = 0
            visited[i][j+1] = 0

print(ans)