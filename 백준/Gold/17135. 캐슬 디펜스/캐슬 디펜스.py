from itertools import combinations
from collections import deque

def check(archer):
    temp = [row[:] for row in arr]
    kill = [[0]*M for _ in range(N)]
    cnt = 0

    for i in range(N-1,-1,-1):
        now = []
        for arch in archer:
            q = deque([(i,arch,1)])
            while q:
                y, x, d = q.popleft()
                if temp[y][x] == 1:
                    now.append((y,x))
                    if kill[y][x] == 0:
                        kill[y][x] = 1
                        cnt +=1
                    break

                if d < D:
                    for dd in range(3):
                        ny, nx = y+dy[dd], x+dx[dd]
                        if 0<= ny <N and 0<= nx <M:
                            q.append((ny,nx,d+1))

        for yy, xx in now:
            temp[yy][xx] = 0


    return cnt


N,M,D = map(int, input().split())
arr = [list(map(int, input().split())) for _ in range(N)]
archers = list(combinations([i for i in range(M)], 3))
dx = [-1,0,1]
dy = [0,-1,0]

ans = 0
for a in archers:
    ans = max(ans, check(a))

print(ans)