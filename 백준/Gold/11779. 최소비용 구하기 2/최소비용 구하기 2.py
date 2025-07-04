from collections import defaultdict
import heapq

N = int(input())
M = int(input())

graph = defaultdict(dict)

for i in range(M):
    s, e, v = map(int, input().split())
    if e not in graph[s] or graph[s][e] > v:
        graph[s][e] = v

start, end = map(int, input().split())

distance = [[float('INF'), []] for _ in range(N+1)]
hq = [(0, [start])]
distance[start][0] = 0
distance[start][1] = [start]

while hq:
    dist, path = heapq.heappop(hq)
    now = path[-1]

    if distance[now][0] < dist:
        continue

    for next, d in graph[now].items():
        cost = dist + d
        if distance[next][0] > cost:
            new_path = path + [next]
            distance[next][0] = cost
            distance[next][1] = new_path
            heapq.heappush(hq, (cost, new_path))

# 최단 거리 및 경로 출력 예시
print(distance[end][0])
print(len(distance[end][1]))
print(*distance[end][1])
