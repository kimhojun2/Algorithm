from collections import deque

N,M = map(int, input().split())

graph = [list(map(int, input().split())) for _ in range(N)]
dy = [0,0,1,-1]
dx = [1,-1,0,0]


def melting():
    q = deque()
    q.append((0,0))
    visited[0][0] = 1

    melt = False

    while q:
        y, x = q.popleft()

        for d in range(4):
            ny, nx = y + dy[d], x + dx[d]
            if 0<=ny<N and 0<=nx<M:
                # 공기라면
                if graph[ny][nx] == 0 and visited[ny][nx] == 0:
                    visited[ny][nx] = 1
                    q.append((ny,nx))

                # 치즈라면
                elif graph[ny][nx] == 1:
                    visited[ny][nx] += 1
                    melt = True


    return melt





time = 0
while True:
    visited = [[0]*M for _ in range(N)]

    melt = melting()

    for i in range(N):
        for j in range(M):
            if visited[i][j] >= 2:
                graph[i][j] = 0

    if not melt:
        print(time)
        break

    time += 1