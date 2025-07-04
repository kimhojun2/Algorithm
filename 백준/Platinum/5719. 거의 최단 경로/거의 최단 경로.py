from collections import defaultdict, deque
import heapq
import sys
input = sys.stdin.readline

INF = float('inf')

def dijkstra(start, graph, N, removed):
    distance = [INF] * N
    trace = [[] for _ in range(N)]
    distance[start] = 0
    hq = [(0, start)]

    while hq:
        dist, now = heapq.heappop(hq)
        if distance[now] < dist:
            continue

        for next, cost in graph[now]:
            if (now, next) in removed:
                continue
            new_cost = dist + cost
            if distance[next] > new_cost:
                distance[next] = new_cost
                trace[next] = [now]
                heapq.heappush(hq, (new_cost, next))
            elif distance[next] == new_cost:
                trace[next].append(now)

    return distance, trace

def check_path(trace, end, removed, graph):
    q = deque()
    q.append(end)
    visited = [False] * len(trace)

    while q:
        now = q.popleft()
        if visited[now]: continue
        visited[now] = True
        for prev in trace[now]:
            removed.add((prev, now))
            q.append(prev)

while True:
    N, M = map(int, input().split())
    if N == 0 and M == 0:
        break

    S, D = map(int, input().split())
    graph = defaultdict(list)
    for _ in range(M):
        u, v, p = map(int, input().split())
        graph[u].append((v, p))

    removed = set()
    distance, trace = dijkstra(S, graph, N, removed)

    check_path(trace, D, removed, graph)

    distance2, _ = dijkstra(S, graph, N, removed)

    print(-1 if distance2[D] == INF else distance2[D])
