N = int(input())
arr = list(map(int, input().split()))
dp = [0] * N

for i in range(N):
    for j in range(i+1,N):
        if arr[i] < arr[j]:
            dp[j] = max(dp[i] + 1, dp[j])

print(max(dp)+1)