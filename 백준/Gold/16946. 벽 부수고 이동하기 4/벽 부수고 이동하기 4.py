from collections import deque

dy = [0, 0, 1, -1]
dx = [1, -1, 0, 0]

def bfs(i, j, area_id):
    q = deque()
    q.append((i, j))
    visited[i][j] = area_id
    area = [(i, j)]
    size = 1

    while q:
        y, x = q.popleft()
        for d in range(4):
            ny, nx = y + dy[d], x + dx[d]
            if 0 <= ny < N and 0 <= nx < M and graph[ny][nx] == '0' and visited[ny][nx] == 0:
                visited[ny][nx] = area_id
                q.append((ny, nx))
                area.append((ny, nx))
                size += 1
    return size

N, M = map(int, input().split())
graph = [list(input()) for _ in range(N)]
visited = [[0] * M for _ in range(N)]
area_size = dict()
area_id = 1

for i in range(N):
    for j in range(M):
        if graph[i][j] == '0' and visited[i][j] == 0:
            size = bfs(i, j, area_id)
            area_size[area_id] = size
            area_id += 1


for i in range(N):
    row = ''
    for j in range(M):
        if graph[i][j] == '1':
            adj = set()
            for d in range(4):
                ny, nx = i + dy[d], j + dx[d]
                if 0 <= ny < N and 0 <= nx < M:
                    aid = visited[ny][nx]
                    if aid:
                        adj.add(aid)
            cnt = 1 + sum(area_size[aid] for aid in adj)
            row += str(cnt % 10)
        else:
            row += '0'
    print(row)
