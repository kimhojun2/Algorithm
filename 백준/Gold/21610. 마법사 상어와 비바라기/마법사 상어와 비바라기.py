import sys
from collections import deque

# input = sys.stdin.readline

N, M = map(int, input().split())
arr = [list(map(int, input().split())) for _ in range(N)]
di = [0, -1, -1, -1, 0, 1, 1, 1]
dj = [-1, -1, 0, 1, 1, 1, 0, -1]
visited = [[0] * N for _ in range(N)]

def move_cloud(y, x, d, s):
    ny = (y + di[d-1] * s) % N
    nx = (x + dj[d-1] * s) % N
    return ny, nx

def water_bug(cloud_positions):
    for y, x in cloud_positions:
        cnt = 0
        for i in [1, 3, 5, 7]:
            ny, nx = y + di[i], x + dj[i]
            if 0 <= ny < N and 0 <= nx < N and arr[ny][nx] > 0:
                cnt += 1
        arr[y][x] += cnt

cloud = [(N-1, 0), (N-1, 1), (N-2, 0), (N-2, 1)]

for m in range(M):
    d, s = map(int, input().split())
    moved_clouds = []

    for y, x in cloud:
        ny, nx = move_cloud(y, x, d, s)
        arr[ny][nx] += 1
        visited[ny][nx] = 1
        moved_clouds.append((ny, nx))

    water_bug(moved_clouds)

    next_cloud = []
    for i in range(N):
        for j in range(N):
            if arr[i][j] >= 2 and visited[i][j] == 0:
                arr[i][j] -= 2
                next_cloud.append((i, j))
            visited[i][j] = 0

    cloud = next_cloud

ans = 0
for row in arr:
    total = sum(row)
    ans += total

print(ans)