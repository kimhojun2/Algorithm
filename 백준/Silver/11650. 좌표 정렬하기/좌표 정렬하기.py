import heapq
N = int(input())
pq = []

for i in range(N):
    x,y = map(int, input().split())
    heapq.heappush(pq,(x,y))

while pq:
    x, y = heapq.heappop(pq)
    print(x,y)