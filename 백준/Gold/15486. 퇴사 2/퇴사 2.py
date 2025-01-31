import sys

input = sys.stdin.readline

N = int(input())

dp = [0]*(N+2)
arr = {}
for i in range(1,N+1):
    time, value = map(int, input().split())
    arr[i] = (time, value)

for i in range(N,0,-1):
    if i+arr[i][0] > N+1:
        dp[i] = dp[i + 1]
        continue

    dp[i] = max(dp[i+1],dp[i+arr[i][0]] + arr[i][1])

print(dp[1])