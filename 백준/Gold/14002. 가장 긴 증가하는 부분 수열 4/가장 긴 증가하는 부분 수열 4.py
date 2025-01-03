N = int(input())
arr = list(map(int, input().split()))

def LIS():
    dp = [1] * N
    for i in range(N):
        for j in range(i):
            if arr[j] < arr[i] and dp[i] < dp[j] + 1:
                dp[i] = dp[j] + 1


    L = max(dp)
    print(L)
    ans = []
    for idx in range(N-1,-1,-1):
        if dp[idx] == L:
            ans.append(arr[idx])
            L -= 1
    ans.reverse()
    print(*ans)

LIS()