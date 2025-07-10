from collections import deque
import sys
input = sys.stdin.readline

def bfs():
    q = deque()
    # (y,x,k)
    q.append((0,0,0))
    visited[0][0][0] = 1
    while q:
        y,x,k = q.popleft()

        if y == N-1 and x == M-1: break


        for d in range(4):
            ny,nx = y+dy[d], x+dx[d]
            if 0<=ny<N and 0<=nx<M:
                # 이동이 가능한 공간
                if graph[ny][nx] == '0' and visited[ny][nx][k] == 0:
                    visited[ny][nx][k] = visited[y][x][k] + 1
                    q.append((ny,nx,k))
                # 이동이 불가능한 공간
                else:
                    if k+1 <= K:
                        if visited[ny][nx][k+1] == 0 and visited[ny][nx][k+1] < visited[y][x][k]:
                            visited[ny][nx][k+1] = visited[y][x][k] + 1
                            q.append((ny,nx,k+1))

    if sum(visited[N-1][M-1]) == 0: return -1
    else:
        m = 1000001
        for k in visited[N-1][M-1]:
            if k == 0: continue
            else: m = min(m,k)
        return m


N,M,K = map(int, input().split())

graph = [list(input().rstrip()) for _ in range(N)]
dy = [0,0,1,-1]
dx = [1,-1,0,0]
visited = [[[0]*(K+1) for __ in range(M)]for _ in range(N)]

ans = bfs()
print(ans)