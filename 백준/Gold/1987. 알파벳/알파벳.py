def backtracking(y, x, visited_bit, cnt):
    global ans

    ans = max(ans, cnt)
    if ans == 26:   # 알파벳 다 썼으면 조기 종료
        return

    for d in range(4):
        ny, nx = y + dy[d], x + dx[d]
        if 0 <= ny < N and 0 <= nx < M:
            bit = 1 << (ord(graph[ny][nx]) - 65)
            if not visited_bit & bit:
                backtracking(ny, nx, visited_bit | bit, cnt + 1)


N, M = map(int, input().split())
graph = [list(input().strip()) for _ in range(N)]

dy = [0, 0, 1, -1]
dx = [1, -1, 0, 0]
ans = 1

start_bit = 1 << (ord(graph[0][0]) - 65)
backtracking(0, 0, start_bit, 1)

print(ans)
