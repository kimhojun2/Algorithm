from collections import deque

di = [0, 0, 1, -1]
dj = [1, -1, 0, 0]

def solution(land):
    N = len(land)
    M = len(land[0])
    visited = [[0] * M for _ in range(N)]
    answer = 0

    def bfs(i, j):
        q = deque([(i, j)])
        visited[i][j] = 1
        total = 0
        check = set()
        
        while q:
            y, x = q.popleft()
            total += 1
            check.add(x)
            for d in range(4):
                ny, nx = y + di[d], x + dj[d]
                if 0 <= ny < N and 0 <= nx < M and not visited[ny][nx] and land[ny][nx] == 1:
                    visited[ny][nx] = 1
                    q.append((ny, nx))
        
        return total, check

    column = [0] * M

    for i in range(N):
        for j in range(M):
            if land[i][j] == 1 and not visited[i][j]:
                oil, cols = bfs(i, j)
                for col in cols:
                    column[col] += oil

    answer = max(column)
    return answer
