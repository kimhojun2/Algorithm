from collections import deque

M, N, H = map(int, input().split())

arr = [[list(map(int, input().split())) for _ in range(N)] for __ in range(H)]
visited = [[[0 for _ in range(M)] for _ in range(N)] for _ in range(H)]

def bfs():
    cnt = N * M * H
    q = deque()

    for i in range(H):
        for j in range(N):
            for k in range(M):
                if arr[i][j][k] == 1:
                    q.append((i, j, k))
                    visited[i][j][k] = 1
                    cnt -= 1
                elif arr[i][j][k] == -1:
                    cnt -= 1

    if cnt == 0:
        return 0

    while q:
        i, j, k = q.popleft()

        for di, dj, dk in [(1, 0, 0), (-1, 0, 0), (0, 1, 0), (0, -1, 0), (0, 0, 1), (0, 0, -1)]:
            ni, nj, nk = i + di, j + dj, k + dk
            if 0 <= ni < H and 0 <= nj < N and 0 <= nk < M:
                if visited[ni][nj][nk] == 0 and arr[ni][nj][nk] == 0:
                    visited[ni][nj][nk] = visited[i][j][k] + 1
                    arr[ni][nj][nk] = 1
                    q.append((ni, nj, nk))
                    cnt -= 1

    if cnt > 0:
        return -1

    ans = 0
    for i in range(H):
        for j in range(N):
            for k in range(M):
                ans = max(ans, visited[i][j][k])

    return ans - 1

print(bfs())
