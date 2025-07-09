from collections import deque

def bfs(y,x,cnt,level):
    if level == T:
        global ans
        ans = max(cnt,ans)
        return

    for d in range(4):
        ny, nx = y+dy[d],x+dx[d]
        if ny<0 or nx<0 or ny>=R or nx>=C: continue
        if arr[ny][nx] == '#': continue
        if arr[ny][nx] == '.' or arr[ny][nx] == 'G':
            bfs(ny,nx,cnt,level+1)
        elif arr[ny][nx] == 'S':
            arr[ny][nx] = '.'
            bfs(ny,nx,cnt+1,level+1)
            arr[ny][nx] ='S'


R, C, T = map(int, input().split())
arr = []
sy,sx =-1,-1
dy = [0,0,1,-1]
dx = [1,-1,0,0]
sw = []

for i in range(R):
    S = list(input())
    arr.append(S)
    if sy != -1 and sx != -1: continue
    for j in range(C):
        if S[j] == 'G':
            sy, sx = i, j

ans = 0
visited = [[0] * R for _ in range(C)]
bfs(sy,sx, 0,0)
print(ans)