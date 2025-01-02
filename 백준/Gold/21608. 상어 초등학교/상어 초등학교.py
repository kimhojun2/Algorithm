import sys

input = sys.stdin.readline

N = int(input())

di = [1, -1, 0, 0]
dj = [0, 0, 1, -1]

dic = {}
arr = [[0] * N for _ in range(N)]

# 학생 배치
for _ in range(N * N):
    lst = list(map(int, input().split()))
    student, likes = lst[0], lst[1:]
    dic[student] = likes

    max_empty, max_friends = -1, -1
    min_y, min_x = N, N

    for y in range(N):
        for x in range(N):
            if arr[y][x] != 0:
                continue

            empty, friends = 0, 0
            for d in range(4):
                ny, nx = y + di[d], x + dj[d]
                if 0 <= ny < N and 0 <= nx < N:
                    if arr[ny][nx] == 0:
                        empty += 1
                    elif arr[ny][nx] in likes:
                        friends += 1

            if (friends > max_friends or
                (friends == max_friends and empty > max_empty) or
                (friends == max_friends and empty == max_empty and (y, x) < (min_y, min_x))):
                min_y, min_x = y, x
                max_friends = friends
                max_empty = empty

    arr[min_y][min_x] = student

# 점수 계산
score = 0
for i in range(N):
    for j in range(N):
        cnt = 0
        for d in range(4):
            ni, nj = i + di[d], j + dj[d]
            if 0 <= ni < N and 0 <= nj < N and arr[ni][nj] in dic[arr[i][j]]:
                cnt += 1

        if cnt == 1:
            score += 1
        elif cnt == 2:
            score += 10
        elif cnt == 3:
            score += 100
        elif cnt == 4:
            score += 1000

print(score)
