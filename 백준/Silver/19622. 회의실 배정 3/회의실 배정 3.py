N = int(input())
meetings = []

for i in range(N):
    meetings.append(list(map(int,input().split())))

dp = [0] * N
dp[0] = meetings[0][2]
for i in range(1, N):
  dp[i] = max(dp[i - 1], dp[i - 2] + meetings[i][2])

print(dp[N - 1])