from collections import deque

q = deque()
N = int(input())
for i in range(N,0,-1):
    q.append(i)

while len(q) > 1:
    q.pop()
    now = q.pop()
    q.appendleft(now)

print(*q)