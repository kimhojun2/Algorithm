import sys
import heapq
from collections import defaultdict

input = sys.stdin.readline

N, E = map(int, input().split())
dic = defaultdict(dict)
for _ in range(E):
    a, b, c = map(int, input().split())
    dic[a][b] = c
    dic[b][a] = c

v1, v2 = map(int, input().split())

def dijkstra(start):
    distance = [float('inf')] * (N+1)
    distance[start] = 0
    q = []
    heapq.heappush(q, (0, start))
    
    while q:
        dist, now = heapq.heappop(q)
        
        if dist > distance[now]:
            continue
        
        for i in dic[now]:
            cost = dist + dic[now][i]
            if cost < distance[i]:
                distance[i] = cost
                heapq.heappush(q, (cost, i))
    
    return distance

s_e = dijkstra(1)
v1_e = dijkstra(v1)
v2_e = dijkstra(v2)

s_v1_v2_e = s_e[v1] + v1_e[v2] + v2_e[N]
s_v2_v1_e = s_e[v2] + v2_e[v1] + v1_e[N]

ans = min(s_v1_v2_e, s_v2_v1_e)
if ans >= float('inf'):
    print(-1)
else:
    print(ans)
