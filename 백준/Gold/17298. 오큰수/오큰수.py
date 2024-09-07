import sys
import heapq

input = sys.stdin.readline

N = int(input())
arr = list(map(int, input().split()))
q = []
dp = [0]*N
for i in range(N-1,-1,-1):
    if i == N-1:
        dp[i] = -1
        heapq.heappush(q,arr[i])
    else:

        while q and arr[i] >= q[0]:
            now = heapq.heappop(q)
        if q:
            dp[i] = q[0]
        else:
            dp[i] = -1
        heapq.heappush(q,arr[i])

print(*dp)