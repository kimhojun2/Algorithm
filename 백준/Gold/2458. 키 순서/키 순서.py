import sys
from collections import deque

# input = sys.stdin.readline
N, M = map(int, input().split())
taller = {}
smaller = {}
for m in range(M):
    a, b = map(int, input().split())
    if a not in smaller:
        smaller[a] = [b]
    else:
        smaller[a].append(b)

    if b not in taller:
        taller[b] = [a]
    else:
        taller[b].append(a)

ans = 0
for i in range(1,N+1):
    check = [0] * (N + 1)
    q = deque()
    q.append(i)
    check[i] = 1
    while q:
        now = q.popleft()
        if now in smaller:
            for next in smaller[now]:
                if check[next]:
                    continue
                q.append(next)
                check[next] = 1
    q.append(i)
    while q:
        now = q.popleft()
        if now in taller:
            for next in taller[now]:
                if check[next]:
                    continue
                q.append(next)
                check[next] = 1

    if 0 not in check[1:]:
        ans += 1
    # print(check)
print(ans)
# print(taller)
# print(smaller)
