T = int(input())

for tc in range(T):
    n = int(input())
    graph = [list(map(int, input().split())) for _ in range(2)]
    # [안뽑, 위, 아래]
    dp = [[0,0,0] for _ in range(n)]
    dp[0] = [0,graph[0][0], graph[1][0]]

    for i in range(1,n):
        dp[i] = [max(dp[i-1]),graph[0][i] + max(dp[i-1][0], dp[i-1][2]), graph[1][i] + max(dp[i-1][0],dp[i-1][1])]

    print(max(dp[n-1]))