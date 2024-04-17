# 11047 동전 0
from collections import deque

N, K = map(int, input().split())

money = deque()
for i in range(N):
    m = int(input())
    money.appendleft(m)

cnt = 0
for j in range(N):
    if K - money[j] < 0:
        pass

    elif K - money[j] >= 0:
        while K >= money[j]:
            K -= money[j]
            cnt += 1
    else:
        break

print(cnt)