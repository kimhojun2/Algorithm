import sys
import heapq

input = sys.stdin.readline
N = int(input())
q = []
for i in range(N):
    now = int(input())
    heapq.heappush(q, now)

ans = 0
while len(q) > 1:
    a = heapq.heappop(q)
    b = heapq.heappop(q)
    new = a + b

    ans += new
    heapq.heappush(q, new)

print(ans)