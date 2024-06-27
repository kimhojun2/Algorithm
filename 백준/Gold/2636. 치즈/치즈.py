from collections import deque

N, M = map(int, input().split())
arr = []
cheese = 0
for i in range(N):
    arr.append(list(map(int, input().split())))
    cheese += sum(arr[i])

dx = [0,0,1,-1]
dy = [1,-1,0,0]

time = 1
def bfs():
    q = deque([(0,0)])
    melting = deque()
    while q:
        x, y = q.popleft()
        for d in range(4):
            nx, ny = x +dx[d], y + dy[d]
            if 0<= nx < N and 0 <= ny < M and not visited[nx][ny]:
                visited[nx][ny] = 1
                if arr[nx][ny] == 0:
                    q.append((nx, ny))

                else:
                    melting.append((nx, ny))

    for x, y in melting:
        arr[x][y] = 0

    return len(melting)


while True:
    visited = [[0]* M for _ in range(N)]
    melting_cheese = bfs()
    cheese -= melting_cheese
    if cheese == 0:
        print(time)
        print(melting_cheese)
        break

    time += 1
