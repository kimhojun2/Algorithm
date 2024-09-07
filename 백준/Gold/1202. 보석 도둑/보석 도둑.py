import sys
import heapq

input = sys.stdin.readline

N, K = map(int, input().split())

jewels = []
for n in range(N):
    m, v = map(int, input().split())
    heapq.heappush(jewels, (m, v))

bags = []
for k in range(K):
    size = int(input())
    bags.append(size)

bags.sort()

possible_jewels = []
ans = 0

for bag in bags:
    while jewels and jewels[0][0] <= bag:
        m, v = heapq.heappop(jewels)
        heapq.heappush(possible_jewels, -v)  

    if possible_jewels:
        ans += -heapq.heappop(possible_jewels)

print(ans)
