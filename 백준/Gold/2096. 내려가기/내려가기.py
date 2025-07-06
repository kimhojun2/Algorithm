import sys
input = sys.stdin.readline

N = int(input())
graph = [list(map(int, input().split())) for _ in range(N)]

max_dp = graph[0][:]
min_dp = graph[0][:]

for i in range(1, N):
    a, b, c = graph[i]
    max0 = max(max_dp[0], max_dp[1]) + a
    max1 = max(max_dp[0], max_dp[1], max_dp[2]) + b
    max2 = max(max_dp[1], max_dp[2]) + c

    min0 = min(min_dp[0], min_dp[1]) + a
    min1 = min(min_dp[0], min_dp[1], min_dp[2]) + b
    min2 = min(min_dp[1], min_dp[2]) + c

    max_dp = [max0, max1, max2]
    min_dp = [min0, min1, min2]

print(max(max_dp), min(min_dp))
