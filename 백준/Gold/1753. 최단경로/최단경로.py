import sys
import heapq

input = sys.stdin.readline

V, E = map(int, input().split())
K = int(input())

dic = {}
for e in range(E):
    u,v,w = map(int, input().split())
    if u not in dic:
        dic[u] = {v:w}
    else:
        if v in dic[u]:
            if w < dic[u][v]:
                dic[u][v] = w
        else:
            dic[u][v] = w

def dijkstra(start):
    q = []
    heapq.heappush(q,(0,start))
    distance = [float('inf') for _ in range(V+1)]
    distance[start] = 0
    while q:
        dist, now = heapq.heappop(q)

        if distance[now] < dist:
            continue

        for i in dic.get(now, {}):
            cost = dist + dic[now][i]
            if cost < distance[i]:
                distance[i] = cost
                heapq.heappush(q,(cost,i))

    return distance

ans = dijkstra(K)

for a in ans[1:]:
    if a == float('inf'):
        print('INF')
    else:
        print(a)