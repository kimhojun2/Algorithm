from collections import deque

M, N = map(int, input().split())

graph = [list(input()) for _ in range(N)]
visited = [[[0]*2 for __ in range(M)] for _ in range(N)]

dy = [0,0,1,-1]
dx = [1,-1,0,0]

q = deque()
q.append((0,0,0))
visited[0][0] = [1,0]

while q:
    y,x,broken_wall = q.popleft()

    for d in range(4):
        ny, nx = y + dy[d], x + dx[d]
        new_wall = broken_wall
        if ny<0 or nx<0 or ny>=N or nx>=M: continue

        # 초기 방문이라면
        if visited[ny][nx][0] == 0:
            if graph[ny][nx] == '1':
                new_wall += 1
            visited[ny][nx][0] = visited[y][x][0] + 1
            visited[ny][nx][1] = new_wall
            q.append((ny,nx,new_wall))

        # 초기 방문이 아니라면
        else:
            if graph[ny][nx] == '1':
                new_wall += 1

            if visited[ny][nx][1] > new_wall:
                visited[ny][nx][0] = visited[y][x][0] + 1
                visited[ny][nx][1] = new_wall
                q.append((ny,nx,new_wall))

print(visited[N-1][M-1][1])