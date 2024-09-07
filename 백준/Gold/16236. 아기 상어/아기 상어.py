import sys
from collections import deque
N = int(input())

dx = [-1,0,0,1]
dy = [0,-1,1,0]
arr = []
size = 2
cnt = 0

for i in range(N):
    arr.append([int(x) for x in sys.stdin.readline().rstrip().split()])
    for j in range(len(arr[i])):
        if arr[i][j] == 9:
            arr[i][j] = 0
            shark_x, shark_y = i, j

def finding_fish(sx,sy):
    global size
    deq = deque()
    deq.append([sx,sy])

    visited = [[False for _ in range(N)] for _ in range(N)]
    distance = [[0 for _ in range(N)] for _ in range(N)]
    can_eat_fish = []

    while deq:
        x, y = deq.popleft()

        for i in range(4):
            nx, ny = x + dx[i], y + dy[i]
            if 0 <= nx < N and 0 <= ny < N:
                if arr[nx][ny] <= size and not visited[nx][ny]:
                    visited[nx][ny] = True
                    distance[nx][ny] = distance[x][y] + 1
                    deq.append([nx,ny])

                    if arr[nx][ny] < size and arr[nx][ny] != 0:
                        can_eat_fish.append([nx ,ny,distance[nx][ny]])

    can_eat_fish.sort(key= lambda x : (x[2],x[0],x[1]))
    return can_eat_fish


ans = 0

while True:
    fishlist = finding_fish(shark_x,shark_y)

    if len(fishlist) == 0:
        print(ans)
        exit(0)

    shark_x, shark_y, move_time = fishlist[0]

    cnt += 1
    if size == cnt:
        cnt = 0
        size += 1

    arr[shark_x][shark_y] = 0
    ans += move_time
   