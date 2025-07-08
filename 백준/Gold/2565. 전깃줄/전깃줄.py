N = int(input())

lst = []

for i in range(N):
    now = list(map(int, input().split()))
    lst.append(now)

lst.sort()
dp = [1] * N
for i in range(N):
    for j in range(i):
        if lst[i][1] > lst[j][1]:
            dp[i] = max(dp[i],dp[j] + 1)

print(N-max(dp))