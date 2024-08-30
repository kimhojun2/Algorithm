T = int(input())

for tc in range(T):
    arr = []
    N = int(input())
    for _ in range(2):
        row = list(map(int, input().split()))
        arr.append(row)
    dp = [[0,0] for _ in range(N)]
    if N == 1:
        print(max(arr[0][0], arr[1][0]))
        continue

    for i in range(N):
        if i == 0:
            dp[0][0] = arr[0][0]
            dp[0][1] = arr[1][0]

        elif i == 1:
            dp[1][0] = dp[0][1] + arr[0][1]
            dp[1][1] = dp[0][0] + arr[1][1]

        else:
            dp[i][0] = max(max(dp[i-2]) + arr[0][i], dp[i-1][1] + arr[0][i])
            dp[i][1] = max(max(dp[i-2]) + arr[1][i], dp[i-1][0] + arr[1][i])

    print(max(dp[N-1]))
