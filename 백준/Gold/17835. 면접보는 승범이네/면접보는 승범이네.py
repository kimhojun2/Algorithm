from collections import defaultdict
import heapq

N, M, K = map(int, input().split())

graph = defaultdict(dict)

distance = [float('INF')] * (N+1)

for i in range(M):
    s, e, v = map(int, input().split())
    if s not in graph[e] or graph[e][s] > v:
        graph[e][s] = v

company = list(map(int, input().split()))


def dijkstra(start):
    hq = []
    heapq.heappush(hq,(0,start))
    distance[start] = 0

    while hq:
        dist, now = heapq.heappop(hq)

        if distance[now] < dist: continue

        for next, d in graph[now].items():
            cost = dist + d
            if distance[next] > cost:
                distance[next] = cost
                heapq.heappush(hq,(cost,next))


    return


for com in company:
    dijkstra(com)

ans = max(distance[1:])
idx = distance.index(ans)

print(idx)
print(ans)