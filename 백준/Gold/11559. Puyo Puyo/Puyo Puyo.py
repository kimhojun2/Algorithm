from collections import deque
import sys

input = sys.stdin.readline

arr = [list(input()) for _ in range(12)]
di = [1, -1, 0, 0]
dj = [0, 0, 1, -1]

def bfs(y, x, color, visited):
    q = deque()
    q.append((y, x))
    visited[y][x] = True
    cnt = 1
    change = [(y, x)]
    while q:
        y, x = q.popleft()
        for d in range(4):
            ny, nx = y + di[d], x + dj[d]
            if 0 <= ny < 12 and 0 <= nx < 6:
                if not visited[ny][nx] and arr[ny][nx] == color:
                    visited[ny][nx] = True
                    q.append((ny, nx))
                    change.append((ny, nx))
                    cnt += 1
    if cnt >= 4:
        for cy, cx in change:
            arr[cy][cx] = '.'
        return True
    return False

def drop_blocks():
    for col in range(6):
        stack = []
        for row in range(11, -1, -1):
            if arr[row][col] != '.':
                stack.append(arr[row][col])
        for row in range(11, -1, -1):
            if stack:
                arr[row][col] = stack.pop(0)
            else:
                arr[row][col] = '.'

ans = 0
while True:
    visited = [[False] * 6 for _ in range(12)]
    exploded = False

    for i in range(12):
        for j in range(6):
            if arr[i][j] != '.' and not visited[i][j]:
                if bfs(i, j, arr[i][j], visited):
                    exploded = True

    if not exploded:
        break

    drop_blocks()
    ans += 1

print(ans)