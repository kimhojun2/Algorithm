import sys

input = sys.stdin.readline

N = int(input())

levels = list(map(int, input().split()))
dp =[0]* (N+1)
for i in range(1,N):
    if levels[i] < levels[i-1]:
        dp[i] = dp[i-1] + 1
    else:
        dp[i] = dp[i-1]

Q = int(input())

for i in range(Q):
    x, y = map(int, input().split())
    print(dp[y-1]-dp[x-1])