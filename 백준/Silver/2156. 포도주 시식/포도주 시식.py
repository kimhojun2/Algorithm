N=int(input())
arr=[int(input()) for _ in range(N)]
dp=[0]*(N+1)
dp[1]=arr[0]

if N>=2:
    dp[2]=arr[0]+arr[1]
    for i in range(3,N+1):
        dp[i]=max(dp[i-3]+sum(arr[i-2:i]), dp[i-2]+arr[i-1], dp[i-1])
        
print(dp[N])