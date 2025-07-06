n = int(input())
m = int(input())

distance = [[float('INF')]*(n+1) for _ in range(n+1)]

for i in range(1,n+1):
    distance[i][i] = 0


for i in range(m):
    s,e,v = map(int, input().split())
    distance[s][e] = min(distance[s][e], v)


for k in range(1,n+1):
    for i in range(1,n+1):
        for j in range(1,n+1):
            if distance[i][j] > distance[i][k] + distance[k][j]:
                distance[i][j] = distance[i][k] + distance[k][j]


for i in range(1,n+1):
    for j in range(1,n+1):
        if distance[i][j] == float('INF'):
            distance[i][j] = 0
        print(distance[i][j], end=' ')

    print()