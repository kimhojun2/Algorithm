import sys
from collections import deque

input = sys.stdin.readline


N, M, K = map(int, input().split())
balls = []
for m in range(M):
    r, c, m, s, d = map(int, input().split())
    balls.append((r - 1, c - 1, m, s, d))

di = [-1, -1, 0, 1, 1, 1, 0, -1]
dj = [0, 1, 1, 1, 0, -1, -1, -1]


def move(y, x, m, s, d):
    ny = (y + di[d] * s) % N
    nx = (x + dj[d] * s) % N
    arr[ny][nx].append((m, s, d))
    return


for k in range(K):
    arr = [[[] for __ in range(N)] for _ in range(N)]

    for r, c, m, s, d in balls:
        move(r, c, m, s, d)

    new_balls = []

    for i in range(N):
        for j in range(N):
            L = len(arr[i][j])

            if L == 0:
                continue

            if L == 1:
                new_balls.append((i, j, *arr[i][j][0]))
            else:
                total_m, total_s, d_odd, d_even = 0, 0, 0, 0

                for now_m, now_s, now_d in arr[i][j]:
                    total_m += now_m
                    total_s += now_s
                    if now_d % 2 == 0:
                        d_even += 1
                    else:
                        d_odd += 1

                if total_m // 5 == 0:
                    continue

                if d_even == L or d_odd == L:
                    next_d = [0, 2, 4, 6]
                else:
                    next_d = [1, 3, 5, 7]

                for ddd in next_d:
                    new_balls.append((i, j, total_m // 5, total_s // L, ddd))

    balls = new_balls

ans = 0
for r, c, m, s, d in balls:
    ans += m

print(ans)
