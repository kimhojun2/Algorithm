import sys
from collections import deque

input = sys.stdin.readline

N, M = map(int, input().split())
dic_heavy = {i: [] for i in range(1, N + 1)}
dic_light = {i: [] for i in range(1, N + 1)}

for _ in range(M):
    heavy, light = map(int, input().split())
    dic_heavy[heavy].append(light)
    dic_light[light].append(heavy)

def count_reachable(start, graph):
    visited = [False] * (N + 1)
    q = deque([start])
    visited[start] = True
    count = 0

    while q:
        now = q.popleft()
        for next in graph[now]:
            if not visited[next]:
                visited[next] = True
                count += 1
                q.append(next)
    return count

mid = (N + 1) // 2
result = 0

for i in range(1, N + 1):
    heavy_count = count_reachable(i, dic_heavy)
    light_count = count_reachable(i, dic_light)
    if heavy_count >= mid or light_count >= mid:
        result += 1

print(result)
