T = int(input())


for tc in range(T):
    N = int(input())
    dp = [[0]*(2) for _ in range(N+1)]
    for i in range(0, N+1):
        if i == 0:
            dp[0] = [1, 0]
        elif i == 1:
            dp[1] = [0, 1]
        else:
            dp[i][0] = dp[i-2][0] + dp[i-1][0]
            dp[i][1] = dp[i-2][1] + dp[i-1][1]
    print(dp[N][0], dp[N][1])