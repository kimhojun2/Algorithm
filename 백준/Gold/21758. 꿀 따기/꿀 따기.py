N = int(input())
arr = list(map(int, input().split()))
dp = [0] * N
dp[0] = arr[0]
for i in range(1, N):
    dp[i] = dp[i - 1] + arr[i]

ans = 0

# Case 1: Bee1, Bee2, Box
for i in range(1, N - 1):
    ans = max(ans, 2 * dp[N - 1] - arr[0] - arr[i] - dp[i])

# Case 2: Box, Bee1, Bee2
for i in range(1, N - 1):
    ans = max(ans, dp[i - 1] + (dp[N - 1] - arr[N - 1] - arr[i]))

# Case 3: Bee1, Box, Bee2
for i in range(1, N - 1):
    ans = max(ans, (dp[i] - arr[0]) + (dp[N - 1] - dp[i - 1] - arr[N - 1]))

print(ans)
