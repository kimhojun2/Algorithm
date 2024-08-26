N = int(input())
arr = []

for i in range(N):
    T, P = map(int, input().split())
    arr.append((T, P))

dp = [0] * (N + 1)

for j in range(N-1, -1, -1):
    if j + arr[j][0] <= N:
        dp[j] = max(dp[j + arr[j][0]] + arr[j][1], dp[j + 1])
    else:
        dp[j] = dp[j + 1]

print(dp[0])