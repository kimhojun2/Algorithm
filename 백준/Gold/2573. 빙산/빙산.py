import sys

input = sys.stdin.readline

N, M = map(int, input().split())

arr = [list(map(int, input().split())) for _ in range(N)]
di = [0, 0, 1, -1]
dj = [1, -1, 0, 0]


def melt():
    nums = 0
    yy, xx = -1, -1
    new_arr = [[0] * M for _ in range(N)]

    for i in range(N):
        for j in range(M):
            if arr[i][j] != 0:
                cnt = 0
                for d in range(4):
                    ni, nj = i + di[d], j + dj[d]
                    if 0 <= ni < N and 0 <= nj < M and arr[ni][nj] == 0:
                        cnt += 1
                new_height = max(0, arr[i][j] - cnt)
                new_arr[i][j] = new_height

                if new_height > 0:
                    nums += 1
                    if yy == -1 and xx == -1:
                        yy, xx = i, j
    return new_arr, nums, yy, xx


def check(y, x):
    stack = [(y, x)]
    visited = [[0] * M for _ in range(N)]
    visited[y][x] = 1
    B = 1
    while stack:
        y, x = stack.pop()

        for d in range(4):
            ny, nx = y + di[d], x + dj[d]
            if 0 <= ny < N and 0 <= nx < M:
                if arr[ny][nx] != 0 and visited[ny][nx] == 0:
                    visited[ny][nx] = 1
                    stack.append((ny, nx))
                    B += 1

    return B


ans = 0
while True:
    now, now_c, yy, xx = melt()
    ans += 1
    arr = now
    if now_c == 0:
        print(0)
        break
    B = check(yy, xx)
    if now_c != B:
        print(ans)
        break
