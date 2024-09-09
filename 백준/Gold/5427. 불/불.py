import sys
from collections import deque

input = sys.stdin.readline
di = [0, 0, 1, -1]
dj = [1, -1, 0, 0]

T = int(input())
for tc in range(T):
    person = deque()
    fire = deque()
    arr = []
    w, h = map(int, input().split())
    for i in range(h):
        row = list(input().rstrip())
        for j in range(w):
            if row[j] == '@':
                person.append((i, j))
            elif row[j] == '*':
                fire.append((i, j))
        arr.append(row)

    visited = [[-1] * w for _ in range(h)]
    visited[person[0][0]][person[0][1]] = 0
    ans = float('inf')

    while person:
        stop = False

        F = len(fire)
        for f in range(F):
            y, x = fire.popleft()
            for d in range(4):
                ny, nx = y + di[d], x + dj[d]
                if 0 <= ny < h and 0 <= nx < w:
                    if arr[ny][nx] == '.' or arr[ny][nx] == '@':
                        arr[ny][nx] = '*'
                        fire.append((ny, nx))

        P = len(person)
        for p in range(P):
            py, px = person.popleft()
            for dd in range(4):
                next_y, next_x = py + di[dd], px + dj[dd]

                if next_y < 0 or next_y >= h or next_x < 0 or next_x >= w:
                    ans = visited[py][px] + 1
                    stop = True
                    break

                if arr[next_y][next_x] == '.' and visited[next_y][next_x] == -1:
                    visited[next_y][next_x] = visited[py][px] + 1
                    person.append((next_y, next_x))

            if stop:
                break

        if stop:
            break

    if ans == float('inf'):
        print('IMPOSSIBLE')
    else:
        print(ans)
