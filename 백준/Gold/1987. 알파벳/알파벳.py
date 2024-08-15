# 백준 알파벳(1987)
import sys
input = sys.stdin.readline

R, C = map(int, input().split())
arr = [list(input().strip()) for _ in range(R)]

di = [0,0,1,-1]
dj = [1,-1,0,0]
check = [0] * 26
visited = [[0] * C for _ in range(R)]
visited[0][0] = 1
start = arr[0][0]
check[ord(start)-65] = 1
cnt = 1

def dfs(y, x, total):
    global cnt
    cnt = max(cnt, total)
    for d in range(4):
        ny, nx = y + di[d], x + dj[d]
        if 0<= ny < R and 0 <= nx < C and not visited[ny][nx]:
            now = arr[ny][nx]
            num = ord(now) - 65
            if not check[num]:
                visited[ny][nx] = 1
                check[num] = 1
                dfs(ny, nx, total + 1)
                check[num] = 0
                visited[ny][nx] = 0

dfs(0, 0, 1)
print(cnt)
