import sys
from collections import deque

input = sys.stdin.readline
t = int(input())

for tc in range(t):
    shops = []
    N = int(input())
    start_x, start_y = map(int, input().split())
    q = deque()
    q.append((start_x,start_y))
    visited = [0] * (N+1)
    for n in range(N):
        sx, sy = map(int, input().split())
        shops.append((sx,sy))


    end_x, end_y = map(int, input().split())
    ans = "sad"
    while q:
        now_x, now_y = q.popleft()

        if abs(now_x - end_x) + abs(now_y - end_y) <= 1000:
            ans = "happy"
            break

        for i in range(N):
            if visited[i] == 0:
                next_x, next_y = shops[i]
                if abs(now_x - next_x) + abs(now_y - next_y) <= 1000:
                    visited[i] = 1
                    q.append((next_x,next_y))


    print(ans)


