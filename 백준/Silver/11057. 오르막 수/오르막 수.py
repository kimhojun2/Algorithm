N = int(input())
dp = [[0]*11 for _ in range(N)]
dp[0] = [1,1,1,1,1,1,1,1,1,1,10]

for i in range(2,N+1):
    for j in range(11):
        if j == 10:
            dp[i-1][10] = sum(dp[i-1]) % 10007

        elif j == 0:
            dp[i-1][0] = dp[i-2][10]

        else:
            dp[i-1][j] = dp[i-1][j-1] - dp[i-2][j-1]

print(dp[N-1][10])