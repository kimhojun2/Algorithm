import sys
from collections import deque

input = sys.stdin.readline
R, C = map(int, input().split())
arr = [list(input().strip()) for _ in range(R)]

di = [0, 0, 1, -1]
dj = [1, -1, 0, 0]

visited = [[0] * C for _ in range(R)]
q = deque()
water = deque()
DY, DX = -1, -1

for i in range(R):
    for j in range(C):
        if arr[i][j] == 'S':
            q.append((i, j))
            visited[i][j] = 1
        elif arr[i][j] == '*':
            water.append((i, j))
        elif arr[i][j] == 'D':
            DY, DX = i, j

while q:
    # Spread water
    for _ in range(len(water)):
        fy, fx = water.popleft()
        for d in range(4):
            nfy, nfx = fy + di[d], fx + dj[d]
            if 0 <= nfy < R and 0 <= nfx < C and arr[nfy][nfx] == '.':
                arr[nfy][nfx] = '*'
                water.append((nfy, nfx))

    # Move hedgehog
    for _ in range(len(q)):
        y, x = q.popleft()
        for d in range(4):
            ny, nx = y + di[d], x + dj[d]
            if 0 <= ny < R and 0 <= nx < C and visited[ny][nx] == 0:
                if arr[ny][nx] == '.':
                    visited[ny][nx] = visited[y][x] + 1
                    q.append((ny, nx))
                elif arr[ny][nx] == 'D':
                    print(visited[y][x])
                    sys.exit()

print('KAKTUS')
