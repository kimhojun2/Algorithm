import heapq
import sys

input = sys.stdin.readline
N = int(input())
lst = []

for n in range(N):
    now = int(input())
    if now != 0:
        # lst.append(now)
        heapq.heappush(lst, now)

    else:
        if not lst:
            print(0)
        else:
            value = heapq.heappop(lst)
            print(value)