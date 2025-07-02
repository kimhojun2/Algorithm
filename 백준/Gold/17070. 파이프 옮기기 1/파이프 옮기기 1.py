import sys
input = sys.stdin.readline

N = int(input())
arr = [list(map(int, input().split())) for _ in range(N)]
dp = [[[0]*3 for _ in range(N)] for _ in range(N)]

dp[0][1][0] = 1

for y in range(N):
    for x in range(2, N):
        if arr[y][x] == 1:
            continue

        # 가로
        dp[y][x][0] = dp[y][x-1][0] + dp[y][x-1][2] if arr[y][x-1] == 0 else 0

        # 세로
        if y > 0:
            dp[y][x][1] = dp[y-1][x][1] + dp[y-1][x][2] if arr[y-1][x] == 0 else 0

        # 대각선
        if y > 0 and arr[y-1][x] == 0 and arr[y][x-1] == 0 and arr[y-1][x-1] == 0:
            dp[y][x][2] = dp[y-1][x-1][0] + dp[y-1][x-1][1] + dp[y-1][x-1][2]

# 정답: (N-1,N-1)에 도달하는 모든 방향의 경로 수 합
print(sum(dp[N-1][N-1]))
