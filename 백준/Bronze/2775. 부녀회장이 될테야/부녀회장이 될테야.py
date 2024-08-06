T = int(input())

for tc in range(T):
    k = int(input())
    n = int(input())
    dp = [[0]*n for _ in range(k+1)]

    for i in range(k+1):
        for j in range(n):
            if i == 0:
                dp[i][j] = j+1
                continue

            if j == 0:
                dp[i][j] = 1
                continue

            dp[i][j] = dp[i][j-1] + dp[i-1][j]

    print(dp[k][n-1])
