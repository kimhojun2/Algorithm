from collections import deque

K = int(input())
W, H = map(int, input().split())
arr = [list(map(int, input().split())) for _ in range(H)]
directions_horse = [(1, 2), (2, 1), (2, -1), (1, -2), (-1, -2), (-2, -1), (-2, 1), (-1, 2)]
directions_monkey = [(0, 1), (0, -1), (1, 0), (-1, 0)]

def bfs(y, x):
    visited = [[[0] * (K + 1) for _ in range(W)] for _ in range(H)]
    q = deque()
    q.append((y, x, 0)) 
    visited[y][x][0] = 1

    while q:
        i, j, limit = q.popleft()

        if i == H - 1 and j == W - 1:
            return visited[i][j][limit] - 1

        # 말 이동
        if limit < K:
            for di, dj in directions_horse:
                ni, nj = i + di, j + dj
                if 0 <= ni < H and 0 <= nj < W and arr[ni][nj] == 0:
                    if visited[ni][nj][limit + 1] == 0:
                        visited[ni][nj][limit + 1] = visited[i][j][limit] + 1
                        q.append((ni, nj, limit + 1))

        for di, dj in directions_monkey:
            ni, nj = i + di, j + dj
            if 0 <= ni < H and 0 <= nj < W and arr[ni][nj] == 0:
                if visited[ni][nj][limit] == 0:
                    visited[ni][nj][limit] = visited[i][j][limit] + 1
                    q.append((ni, nj, limit))

    return None

ans = bfs(0, 0)
print(-1 if ans is None else ans)
