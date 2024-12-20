import sys

input = sys.stdin.readline

N, M = map(int, input().split())

edges = []
for m in range(M):
    add_edge = list(map(int, input().split()))
    edges.append(add_edge)

def func(N,edges):
    distances = [float('inf') for _ in range(N+1)]
    distances[1] = 0

    for i in range(N-1):
            for u,v,w in edges:
                if distances[u] != float('inf') and distances[u] + w < distances[v]:
                    distances[v] = distances[u] + w

    for u,v,w in edges:
        if distances[u] != float('inf') and distances[u] + w < distances[v]:
            return -1

    return distances[2:]

ans = func(N,edges)
if ans == -1:
    print(-1)
else:
    for cost in ans:
        if cost == float('inf'):
            print(-1)
            continue
        print(cost)