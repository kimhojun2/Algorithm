import heapq
import sys

input = sys.stdin.readline
heap = []

N = int(input().strip())

for _ in range(N):
    x = int(input().strip())
    if x == 0:
        if heap:
            print(heapq.heappop(heap)[1])
        else:
            print(0)
    else:
        heapq.heappush(heap, (abs(x), x))