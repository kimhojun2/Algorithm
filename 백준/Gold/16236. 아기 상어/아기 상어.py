from collections import deque
import heapq

N = int(input())

graph = []
shark_y, shark_x, shark_size = -1, -1, 2

for i in range(N):
    lst = list(map(int, input().split()))
    graph.append(lst)
    if shark_y != -1 and shark_x != -1: continue
    for j in range(N):
        if lst[j] == 9:
            shark_y, shark_x = i, j
            lst[j] = 0
            break

dy = [0,0,1,-1]
dx = [1,-1,0,0]

def next_fish(sy, sx):
    q = deque()
    q.append((sy,sx))

    visited = [[0]*N for _ in range(N)]
    visited[sy][sx] = 1

    fishes = []

    while q:
        y, x = q.popleft()

        for d in range(4):
            ny, nx = y+dy[d], x+dx[d]
            if 0<= ny<N and 0<=nx<N and not visited[ny][nx] and graph[ny][nx] <= shark_size:
                visited[ny][nx] = visited[y][x] + 1
                q.append((ny,nx))
                if graph[ny][nx] != 0 and graph[ny][nx] < shark_size:
                    heapq.heappush(fishes, (visited[ny][nx]-1, ny, nx))

    if fishes: return heapq.heappop(fishes)
    else: return 0

time = 0
cnt = 0
while True:
    next = next_fish(shark_y, shark_x)
    if  next == 0: break
    else:
        plus_time, shark_y, shark_x = next[0], next[1], next[2]

    cnt += 1
    if cnt == shark_size:
        shark_size += 1
        cnt = 0

    time += plus_time
    graph[shark_y][shark_x] = 0


print(time)