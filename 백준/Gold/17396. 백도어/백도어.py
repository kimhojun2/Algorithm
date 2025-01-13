import sys

input = sys.stdin.readline

import heapq

N, M = map(int, input().split())

vision = list(map(int, input().split()))

dic = {}
for i in range(M):
    s,e,v = map(int, input().split())
    if s not in dic:
        dic[s] = {e:v}
    else:
        dic[s][e] = v

    if e not in dic:
        dic[e] = {s:v}
    else:
        dic[e][s] = v

def dijkstra():
    distance = [float('inf')] * N
    distance[0] = 0
    q = []
    heapq.heappush(q,(0,0))

    while q:
        dist, now = heapq.heappop(q)

        if distance[now] < dist:
            continue

        for new in dic.get(now, {}):
            if vision[new] == 1:
                if new != N-1:
                    continue
            cost = dist + dic[now][new]
            if cost < distance[new]:
                distance[new] = cost
                heapq.heappush(q,(cost, new))
    if distance[N-1] == float('inf'):
        return -1
    else:
        return distance[N-1]


print(dijkstra())