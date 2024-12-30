import sys
import heapq

N,M = map(int, input().split())
lst = list(map(int, input().split()))
arr = list(map(int, input().split()))
heap = []

for i in lst:
    heapq.heappush(heap, -1*i)

ans = 1
for a in arr:
    now = heapq.heappop(heap)
    if -1 *now < a:
        ans = 0
        break

    heapq.heappush(heap,now + a)

print(ans)
