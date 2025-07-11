import heapq

N, K = map(int, input().split())
heap = []
for i in range(N):
    value = int(input())
    heapq.heappush(heap,-value)

ans = 0
while K>0:
    now = -heapq.heappop(heap)
    if now > K: continue
    V = K//now
    ans += V
    K -= (V*now)

print(ans)
