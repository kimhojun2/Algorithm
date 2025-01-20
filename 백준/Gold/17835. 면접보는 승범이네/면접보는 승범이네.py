import sys
import heapq

input = sys.stdin.readline

N, M, K = map(int, input().split())
dic = {}
for i in range(M):
    s,e,v = map(int, input().split())
    if e not in dic:
        dic[e] = {s:v}
    else:
        dic[e][s] = v

lst = list(map(int, input().split()))
q = []
distance = [float('inf') for _ in range(N+1)]
def dijkstra():

    while q:
        dist, now = heapq.heappop(q)

        if distance[now] < dist:
            continue

        for new in dic.get(now, {}):
            cost = dist + dic[now][new]
            if cost < distance[new]:
                distance[new] = cost
                heapq.heappush(q,(cost, new))


for city in lst:
    heapq.heappush(q,(0,city))
    distance[city] = 0

dijkstra()
max_v = -1
max_i = -1
for idx,value in enumerate(distance[1:]):
    if value > max_v:
        max_i = idx + 1
        max_v = value

print(max_i)
print(max_v)