import sys
import heapq

input = sys.stdin.readline

n, m, r = map(int, input().split())
arr = list(map(int, input().split()))
dic = {}
for _ in range(r):
    a, b, l = map(int, input().split())
    if a not in dic:
        dic[a] = {b:l}
    else:
        dic[a][b] = l

    if b not in dic:
        dic[b] = {a:l}

    else:
        dic[b][a] = l


def dijkstra(start, limit):
    q = []
    heapq.heappush(q,(0,start))
    distance[start] = 0
    total = 0
    while q:
        dist, now = heapq.heappop(q)

        if dist > distance[now]:
            continue

        for i in dic.get(now, {}):
            cost = dist + dic[now][i]
            if cost < distance[i] and cost <= limit:
                distance[i] = cost
                heapq.heappush(q,(cost,i))

    for d in range(len(distance[1:])):
        if distance[d+1] != float('inf'):
            total += arr[d]
    return total


ans = 0
for s in range(1, n+1):
    distance = [float('inf') for _ in range(n+1)]
    aaa = dijkstra(s, m)
    ans = max(ans, aaa)

print(ans)
