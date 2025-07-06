from sys import stdin
input = stdin.readline

T = int(input())

for _ in range(T):
    N, M, W = map(int, input().split())
    edges = []

    for _ in range(M):
        s, e, t = map(int, input().split())
        edges.append((s, e, t))
        edges.append((e, s, t))

    for _ in range(W):
        s, e, t = map(int, input().split())
        edges.append((s, e, -t))

    dist = [float('inf')] * (N + 2)
    dist[0] = 0

    for i in range(1, N + 1):
        edges.append((0, i, 0))

    is_negative_cycle = False
    for i in range(N + 1):
        for u, v, cost in edges:
            if dist[u] != float('inf') and dist[v] > dist[u] + cost:
                dist[v] = dist[u] + cost
                if i == N:
                    is_negative_cycle = True

    print("YES" if is_negative_cycle else "NO")
