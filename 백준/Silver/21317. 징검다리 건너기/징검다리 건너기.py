N = int(input())

arr = [[0, 0]]
for _ in range(N - 1):
    now = list(map(int, input().split()))
    arr.append(now)

K = int(input())

dp = [0] * (N + 1)

dp[0] = 0

if N == 1:
    print(0)
elif N == 2:
    print(arr[1][0])
else:
    dp[1] = arr[1][0]
    dp[2] = min(dp[1] + arr[2][0], arr[1][1])

    for i in range(3, N):
        dp[i] = min(dp[i - 1] + arr[i][0], dp[i - 2] + arr[i - 1][1])

    result = dp[N - 1]

    for i in range(3, N):
        dp2 = dp.copy()
        dp2[i] = dp[i - 3] + K

        for j in range(i + 1, N):
            dp2[j] = min(dp2[j - 1] + arr[j][0], dp2[j - 2] + arr[j - 1][1])

        if result > dp2[N - 1]:
            result = dp2[N - 1]

    print(result)