n = int(input())
arr = [0]
dp = [[0]*2 for _ in range(n+1)]
for i in range(n):
    stair = int(input())
    arr.append(stair)

for j in range(1, n+1):
    if j == 1:
        dp[1][0] = arr[1]

    elif j == 2:
        dp[2][0] = dp[1][0] + arr[2]
        dp[2][1] = arr[2]

    else:
        if dp[j-1][0]:
            dp[j][1] = max(dp[j-2][1] + arr[j], dp[j-2][0] + arr[j])
            dp[j][0] = dp[j-1][1] + arr[j]
        else:
            dp[j][0] = dp[j-1][1] + arr[j]
            dp[j][1] = max(dp[j-2][1] + arr[j], dp[j-2][0] + arr[j])

print(max(dp[n]))