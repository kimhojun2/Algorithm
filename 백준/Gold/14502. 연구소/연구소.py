import sys
input = sys.stdin.readline

from collections import deque
import copy

N, M = map(int, input().split())

graph = [list(map(int, input().split())) for _ in range(N)]

dy = [0,0,1,-1]
dx = [1,-1,0,0]

def bfs():
    global ans
    q = deque()
    temp = copy.deepcopy(graph)

    for i in range(N):
        for j in range(M):
            if temp[i][j] == 2:
                q.append((i,j))

    while q:
        y, x = q.popleft()

        for d in range(4):
            ny, nx = y +dy[d], x + dx[d]
            if nx<0 or ny<0 or ny>=N or nx >= M: continue
            if temp[ny][nx] == 0:
                temp[ny][nx] = 2
                q.append((ny,nx))


    cnt = 0
    for i in range(N):
        cnt += temp[i].count(0)

    ans = max(cnt, ans)

def make_wall(cnt):
    if cnt == 3:
        bfs()
        return


    for i in range(N):
        for j in range(M):
            if graph[i][j] == 0:
                graph[i][j] = 1
                make_wall(cnt+1)
                graph[i][j] = 0


ans = 0
make_wall(0)
print(ans)