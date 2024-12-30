import sys
import heapq

input = sys.stdin.readline

N = int(input())
heap = []
for i in range(N):
    now = list(map(int, input().split()))
    if len(now) > 1:
        for j in now[1:]:
            heapq.heappush(heap,-1*j)

    else:
        if heap:
            ans = heapq.heappop(heap)
            print(-1*ans)
        else:
            print(-1)

