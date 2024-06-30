from collections import deque

N, L, R = map(int, input().split())

arr = [list(map(int, input().split())) for _ in range(N)]

dy = [1,-1,0,0]
dx = [0,0,1,-1]

def bfs(y,x):
    global check
    q = deque([(y,x)])
    union = [(y,x)]
    visited[y][x] = 1
    total = arr[y][x]
    while q:
        now = q.popleft()
        now_y, now_x = now[0], now[1]
        for d in range(4):
            ny, nx = now_y + dy[d], now_x + dx[d]
            if 0 <= ny < N and 0 <= nx <N:
                if not visited[ny][nx] and L <= abs(arr[now_y][now_x] - arr[ny][nx]) <= R:
                    visited[ny][nx] = 1
                    union.append((ny,nx))
                    q.append((ny,nx))
                    total += arr[ny][nx]

    value = total//len(union)
    if len(union) > 1:
        check = True
        for y, x in union:
            arr[y][x] = value


cnt = 0
# visited = [[0] * N for _ in range(N)]
while True:
    visited = [[0] * N for _ in range(N)]
    check = False
    for i in range(N):
        for j in range(N):
            if not visited[i][j]:
                bfs(i,j)

    if check:
        cnt += 1
    else:
        break

print(cnt)