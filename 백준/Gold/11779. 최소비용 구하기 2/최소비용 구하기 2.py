import sys
import heapq
input = sys.stdin.readline

N = int(input())
M = int(input())

dic = {}
for _ in range(M):
    A, B, C = map(int, input().split())
    if A not in dic:
        dic[A] = {B: C}
    else:
        if B in dic[A]:
            dic[A][B] = min(dic[A][B], C)
        else:
            dic[A][B] = C

start, end = map(int, input().split())

def dijkstra(start, end):
    q = []
    heapq.heappush(q, (0, start))
    distance = [[float('inf'), []] for _ in range(N + 1)]
    distance[start][0] = 0
    distance[start][1] = [start]

    while q:
        dist, now = heapq.heappop(q)

        if dist > distance[now][0]:
            continue

        for next_node in dic.get(now, {}):
            cost = dist + dic[now][next_node]

            if cost < distance[next_node][0]:
                distance[next_node][0] = cost
                distance[next_node][1] = distance[now][1] + [next_node]
                heapq.heappush(q, (cost, next_node))

    return distance[end]

min_cost, arr = dijkstra(start, end)
print(min_cost)
print(len(arr))
print(*arr)
