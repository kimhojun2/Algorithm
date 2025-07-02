import sys
from collections import deque

input = sys.stdin.readline

N = int(input())
K = int(input())

dy = [0, 1, 0, -1]
dx = [1, 0, -1, 0]

arr = [[0]*N for _ in range(N)]
arr[0][0] = 1

for _ in range(K):
    y, x = map(int, input().split())
    arr[y-1][x-1] = 2

L = int(input())
direction_changes = dict()
for _ in range(L):
    t, d = input().split()
    direction_changes[int(t)] = d

time = 0
y, x, direction = 0, 0, 0
snake = deque()
snake.append((0, 0))

while True:
    time += 1
    ny, nx = y + dy[direction], x + dx[direction]

    if ny < 0 or nx < 0 or ny >= N or nx >= N or arr[ny][nx] == 1:
        break

    if arr[ny][nx] == 2:
        arr[ny][nx] = 1
        snake.append((ny, nx))
    else:

        arr[ny][nx] = 1
        snake.append((ny, nx))
        ty, tx = snake.popleft()
        arr[ty][tx] = 0

    y, x = ny, nx

    if time in direction_changes:
        if direction_changes[time] == 'D':
            direction = (direction + 1) % 4
        else:
            direction = (direction - 1) % 4

print(time)
