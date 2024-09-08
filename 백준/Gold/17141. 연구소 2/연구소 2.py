import sys
from collections import deque
from itertools import combinations

# input = sys.stdin.readline
N, M = map(int, input().split())
arr = list(list(map(int, input().split())) for _ in range(N))

virus = []
for i in range(N):
    for j in range(N):
        if arr[i][j] == 2:
            virus.append((i,j))

di = [0,0,1,-1]
dj = [1,-1,0,0]

def solution(group):
    q = deque(group)
    visited = [[-1] * N for _ in range(N)]
    m_t = 0
    for y,x in q:
        visited[y][x] = 0

    while q:
        y,x = q.popleft()
        for d in range(4):
            ny, nx = y + di[d], x + dj[d]
            if 0<= ny < N and 0<= nx < N and arr[ny][nx] != 1 and visited[ny][nx] == -1:
                q.append((ny,nx))
                visited[ny][nx] = visited[y][x] + 1
                m_t= max(visited[y][x]+1, m_t)

    for i in range(N):
        for j in range(N):
            if visited[i][j] == -1 and arr[i][j] != 1:
                return float('inf')


    return m_t


answer = float('inf')
for group in combinations(virus, M):
    now = solution(group)
    answer = min(now, answer)

if answer == float('inf'):
    print(-1)
else:
    print(answer)