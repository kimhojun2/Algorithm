def solution(n, lighthouse):
    from collections import defaultdict, deque

    graph = defaultdict(list)
    for a, b in lighthouse:
        graph[a].append(b)
        graph[b].append(a)

    degree = [0] * (n + 1)
    for i in range(1, n+1):
        degree[i] = len(graph[i])

    q = deque()
    for i in range(1, n + 1):
        if degree[i] == 1:
            q.append(i)

    visited = [False] * (n + 1)
    light = [0] * (n + 1)  

    while q:
        now = q.popleft()
        visited[now] = True

        for next_node in graph[now]:
            if visited[next_node]:
                continue

            if light[now] == 0:
                light[next_node] = 1

            degree[next_node] -= 1
            if degree[next_node] == 1:
                q.append(next_node)

    return sum(light)
