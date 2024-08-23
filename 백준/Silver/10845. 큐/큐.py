import sys
from collections import deque
input = sys.stdin.readline
N = int(input())
q = deque()

for i in range(N):
    l = list(input().rstrip().split())
    if l[0] == 'push':
        q.append(l[1])
    elif l[0] == 'front':
        if q:
            print(q[0])
        else:
            print(-1)
    elif l[0] == 'back':
        if q:
            print(q[-1])
        else:
            print(-1)
    elif l[0] == 'size':
        print(len(q))
    elif l[0] == 'pop':
        if q:
            now = q.popleft()
            print(now)
        else:
            print(-1)
    else:
        if q:
            print(0)
        else:
            print(1)