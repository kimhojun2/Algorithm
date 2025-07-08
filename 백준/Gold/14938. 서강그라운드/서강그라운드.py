n,m,r = map(int, input().split())

items = [0] + list(map(int, input().split()))

graph = [[float('INF')] * (n+1) for _ in range(n+1)]
for i in range(1,n+1):
    graph[i][i] = 0

for i in range(r):
    s,e,v = map(int, input().split())
    graph[s][e] = v
    graph[e][s] = v


for k in range(1,n+1):
    for i in range(1,n+1):
        for j in range(1,n+1):
            if graph[i][j] > graph[i][k] + graph[k][j]:
                graph[i][j] = graph[i][k] + graph[k][j]


result = 0

for i in range(1,n+1):
    now = 0
    for j in range(1,n+1):
        if graph[i][j] <= m:
            now += items[j]

    if now > result:
        result = now

print(result)