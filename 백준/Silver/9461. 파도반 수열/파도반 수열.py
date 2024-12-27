import sys

input = sys.stdin.readline

T = int(input())

for tc in range(T):
    N = int(input())
    dp = [0]*(N+1)
    if N == 1:
        dp[1] = 1
        print(dp[N])
    elif N == 2:
        dp[2] = 1
        print(dp[N])
    elif N ==3:
        dp[3] = 1
        print(dp[N])
    elif N==4:
        dp[4] = 2
        print(dp[N])
    elif N == 5:
        dp[5] = 2
        print(dp[N])
    else:
        dp[1] = 1
        dp[2] = 1
        dp[3] = 1
        dp[4] = 2
        dp[5] = 2
        for i in range(6,N+1):
            dp[i] = dp[i-1] + dp[i-5]

        print(dp[N])
    # print(dp)