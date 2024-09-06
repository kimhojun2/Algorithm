import sys

sys.setrecursionlimit(10 ** 6)
input = sys.stdin.readline

N = int(input())

arr = [list(map(int, input().split())) for _ in range(N)]
di = [0, 0, 1, -1]
dj = [1, -1, 0, 0]
dp = [[0] * N for _ in range(N)]


def check(y, x):
    if dp[y][x] != 0:
        return dp[y][x]

    dp[y][x] = 1 
    for d in range(4):
        ny, nx = y + di[d], x + dj[d]
        if 0 <= ny < N and 0 <= nx < N:
            if arr[y][x] < arr[ny][nx]:
                dp[y][x] = max(dp[y][x], check(ny, nx) + 1)

    return dp[y][x]


ans = 0
for i in range(N):
    for j in range(N):
        ans = max(ans, check(i, j))

print(ans)