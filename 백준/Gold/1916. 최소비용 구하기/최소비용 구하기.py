from collections import defaultdict
import heapq

N = int(input())
M = int(input())

graph = defaultdict(dict)

for i in range(M):
    s,e,v = map(int, input().split())

    if e not in graph[s] or graph[s][e] > v:
        graph[s][e] = v

start, end = map(int, input().split())

distance = [float('INF')] * (N+1)
hq = []
heapq.heappush(hq,(0,start))
distance[start] = 0
while hq:
    dist, now = heapq.heappop(hq)

    if distance[now] < dist: continue

    for next, d in graph[now].items():
        cost = dist + d
        if cost < distance[next]:
            distance[next] = cost
            heapq.heappush(hq,(cost,next))

print(distance[end])
