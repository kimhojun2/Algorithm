from collections import deque
import copy
N, M = map(int, input().split())

arr = [list(map(int, input().split())) for _ in range(N)]
dy = [1,0,-1,0]
dx = [0,1,0,-1]

def bfs():
    q = deque()
    new_arr = copy.deepcopy(arr)

    for i in range(N):
        for j in range(M):
            if new_arr[i][j] == 2:
                q.append((i,j))

    while q:
        y, x = q.popleft()

        for d in range(4):
            ny, nx = y + dy[d], x + dx[d]

            if 0 <= nx < M and 0 <= ny < N:
                if new_arr[ny][nx] == 0:
                    new_arr[ny][nx] = 2
                    q.append((ny, nx))

    global ans
    cnt = 0
    for i in range(N):
        cnt += new_arr[i].count(0)

    if cnt > ans:
        ans = cnt

def wall(cnt):
    if cnt == 3:
        bfs()
        return

    for i in range(N):
        for j in range(M):
            if arr[i][j] == 0:
                arr[i][j] = 1
                wall(cnt+1)
                arr[i][j] = 0

ans = 0
wall(0)
print(ans)