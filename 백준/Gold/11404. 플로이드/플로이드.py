import sys
import heapq

input = sys.stdin.readline

N = int(input())
M = int(input())

dic = {}

for m in range(M):
    a, b, c = map(int, input().split())
    if a not in dic:
        dic[a] = {b:c}
    else:
        if b in dic[a]:
            if dic[a][b] > c:
                dic[a][b] = c
        else:
            dic[a][b] = c


def dijkstra(start):
    q = []
    heapq.heappush(q, (0, start))
    distance[start] = 0

    while q:
        dist, now = heapq.heappop(q)

        if distance[now] < dist:
            continue

        for i in dic.get(now, {}):
            cost = dist + dic[now][i]
            if cost < distance[i]:
                distance[i] = cost
                heapq.heappush(q, (cost, i))

for j in range(1, N+1):
    distance = [float('inf') for _ in range(N + 1)]
    dijkstra(j)
    for d in distance[1:]:
        if d == float('inf'):
            print(0, end =' ')
        else:
            print(d, end=' ')

    print()
