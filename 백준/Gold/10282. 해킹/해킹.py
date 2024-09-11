import sys
import heapq


input = sys.stdin.readline

T = int(input())
for tc in range(T):
    n, d, c = map(int, input().split())
    dic = {}
    for _ in range(d):
        a, b, t = map(int, input().split())
        if b not in dic:
            dic[b] = {a:t}
        else:
            dic[b][a] = t


    q = []
    heapq.heappush(q, (0, c))
    distance = [float('inf')] * (n+1)
    visited = [0] * (n+1)
    distance[c] = 0
    last = c
    while q:
        dist, now = heapq.heappop(q)

        if visited[now] == 1:
            continue

        visited[now] = 1
        for i in dic.get(now, {}):
            cost = dist + dic[now][i]
            if cost < distance[i]:
                distance[i] = cost
                heapq.heappush(q, (cost,i))

    cnt = 0
    time = 0
    for v in range(1,n+1):
        if visited[v]:
            cnt += 1
            time = max(time, distance[v])

    print(cnt, time)