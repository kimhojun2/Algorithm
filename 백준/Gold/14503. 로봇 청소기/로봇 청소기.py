import sys

input = sys.stdin.readline

N, M = map(int, input().split())
r, c, d = map(int, input().split())
arr = [list(map(int, input().split())) for _ in range(N)]

dy = [-1, 0, 1, 0]
dx = [0, 1, 0, -1]

visited = [[0] * M for _ in range(N)]
cnt = 0


def clean(y, x, dir):
    global cnt

    if arr[y][x] == 0 and not visited[y][x]:
        visited[y][x] = 1
        cnt += 1

    for _ in range(4):
        dir = (dir + 3) % 4
        ny, nx = y + dy[dir], x + dx[dir]

        if 0 <= ny < N and 0 <= nx < M and arr[ny][nx] == 0 and not visited[ny][nx]:
            clean(ny, nx, dir)
            return

    back_dir = (dir + 2) % 4
    ny, nx = y + dy[back_dir], x + dx[back_dir]

    if 0 <= ny < N and 0 <= nx < M and arr[ny][nx] == 0:
        clean(ny, nx, dir)
    else:
        return


clean(r, c, d)
print(cnt)
