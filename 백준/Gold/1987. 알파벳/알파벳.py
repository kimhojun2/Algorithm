def backtracking(y,x, cnt):
    global ans
    for d in range(4):
        ny, nx = y + dy[d], x + dx[d]
        if ny < 0 or nx < 0 or ny >= N or nx >= M: continue
        now = ord(graph[ny][nx]) - 65
        if checklist[now] == 1: continue
        checklist[now] = 1
        backtracking(ny,nx, cnt+1)
        checklist[now] = 0

    ans = max(ans, cnt)

    return


N, M = map(int, input().split())

graph = [list(input()) for _ in range(N)]
visited = [[0]*M for _ in range(N)]
checklist = [0]*26
visited[0][0] = 1
checklist[ord(graph[0][0])-65] = 1

dy = [0,0,1,-1]
dx = [1,-1,0,0]
ans = 1

backtracking(0,0,1)

print(ans)