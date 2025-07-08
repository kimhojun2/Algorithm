import sys
from collections import deque
from itertools import combinations
input = sys.stdin.readline

N, M = map(int, input().split())
graph = [list(map(int, input().split())) for _ in range(N)]

dy = [0, 0, 1, -1]
dx = [1, -1, 0, 0]

# 0인 칸, 바이러스 칸 위치 미리 저장
empty = []
virus = []

for i in range(N):
    for j in range(M):
        if graph[i][j] == 0:
            empty.append((i, j))
        elif graph[i][j] == 2:
            virus.append((i, j))

def spread(temp):
    q = deque(virus)  # 바이러스는 항상 고정된 위치에서 시작
    while q:
        y, x = q.popleft()
        for d in range(4):
            ny, nx = y + dy[d], x + dx[d]
            if 0 <= ny < N and 0 <= nx < M and temp[ny][nx] == 0:
                temp[ny][nx] = 2
                q.append((ny, nx))

def get_safe_area(temp):
    return sum(row.count(0) for row in temp)

ans = 0
for walls in combinations(empty, 3):
    temp = [row[:] for row in graph]  # 얕은 복사로도 충분함
    for y, x in walls:
        temp[y][x] = 1
    spread(temp)
    ans = max(ans, get_safe_area(temp))

print(ans)
