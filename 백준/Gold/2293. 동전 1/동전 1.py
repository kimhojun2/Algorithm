import sys
import heapq


# input = sys.stdin.readline
n, k = map(int, input().split())
coins = []
for _ in range(n):
    now = int(input())
    coins.append(now)

dp = [0] * (k+1)
dp[0] = 1

for coin in coins:
    for i in range(coin, k+1):
        dp[i] += dp[i-coin]


print(dp[k])