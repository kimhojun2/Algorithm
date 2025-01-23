import heapq
N = int(input())
pq = []

for i in range(N):
    x,y = map(int, input().split())
    heapq.heappush(pq,(y,x))

while pq:
    y, x = heapq.heappop(pq)
    print(x,y)