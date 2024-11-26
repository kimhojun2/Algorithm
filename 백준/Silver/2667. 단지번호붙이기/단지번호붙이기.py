import sys
from collections import deque
N = int(input())

arr = [list(input()) for _ in range(N)]
visited = [[0]*N for _ in range(N)]
di = [0,0,1,-1]
dj = [1,-1,0,0]


def bfs(y,x):
    q = deque()
    q.append((y,x))
    visited[y][x] = 1
    arr[y][x] = '0'
    cnt = 1
    while q:
        i, j = q.popleft()
        for d in range(4):
            ni, nj = i + di[d], j + dj[d]
            if 0<= ni <N and 0<= nj < N and visited[ni][nj] == 0 and arr[ni][nj] == '1':
                arr[ni][nj] = '0'
                visited[ni][nj] = 1
                q.append((ni,nj))
                cnt += 1

    return cnt

ans = 0
num = []
for y in range(N):
    for x in range(N):
        if arr[y][x] == '1':
            ans += 1
            num.append(bfs(y,x))

print(ans)
num.sort()
for n in num:
    print(n)