def solution(m, n, puddles):
    answer = 0
    dp = [[0]*m for _ in range(n)]
    dp[0][0] = 1
    for i in range(n):
        for j in range(m):
            if [j+1,i+1] in puddles:
                continue
            if i==0 and j==0:
                continue
            if i == 0:
                dp[i][j] = dp[i][j-1]
            elif j == 0:
                dp[i][j] = dp[i-1][j]
            else:
                dp[i][j] = dp[i-1][j]+dp[i][j-1]
    answer = (dp[n-1][m-1]%1000000007)
    return answer