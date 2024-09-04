import sys

input = sys.stdin.readline

arr = list(map(str, input().rstrip()))

dp = [0]*len(arr)
for i in range(len(arr)):
    if i == 0:
        if arr[i] == '0':
            break
        else:
            dp[0] = 1

    elif i == 1:
        if arr[i] == '0':
            if arr[i-1] == '0' or int(arr[i-1]) > 2:
                break
            else:
                dp[1] = 1

        else:
            if int(arr[0] + arr[1]) <= 26:
                dp[1] = 2
            else:
                dp[1] = 1
    else:
        if arr[i] == '0':
            if arr[i-1] == '0' or int(arr[i-1]) > 2:
                break
            else:
                dp[i] = dp[i-2]

        else:
            if int(arr[i-1]) == 0:
                dp[i] = dp[i-1]
            else:
                if int(arr[i-1] + arr[i]) <= 26:
                    dp[i] = (dp[i-2] + dp[i-1]) % 1000000
                else:
                    dp[i] = dp[i-1]

print(dp[len(arr)-1])


