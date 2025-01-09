N, M = map(int, input().split())

arr = list(map(int, input().split()))

dp = [0] * N
dp[0] = arr[0]

for i in range(1,N):
    dp[i] = dp[i-1] + arr[i]

for m in range(M):
    i, j = map(int, input().split())

    if i == 1:
        print(dp[j-1])
    else:
        print(dp[j-1]-dp[i-2])
