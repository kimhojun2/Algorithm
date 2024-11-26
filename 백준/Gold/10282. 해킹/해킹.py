import sys
import heapq

input = sys.stdin.readline

T = int(input())

def dijkstra(start):
    q = []
    heapq.heappush(q,(0,start))
    distance = [float('inf') for _ in range(n+1)]
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



for tc in range(T):
    dic = {}
    n, d, c = map(int, input().split())
    for i in range(d):
        a,b,s = map(int, input().split())

        if b not in dic:
            dic[b] = {a:s}

        else:
            dic[b][a] = s

    ans = dijkstra(c)
    cnt = 0
    M = 0
    for k in ans:
        if k != float('inf'):
            cnt += 1
            if k > M:
                M = k

    print(cnt, M)
