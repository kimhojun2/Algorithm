import sys
from collections import deque

input = sys.stdin.readline

N = int(input())
M = int(input())
arr = list(list(map(int, input().split())) for _ in range(N))

plan = list(map(int, input().split()))
dic = {i : [] for i in range(N)}
for i in range(N):
    for j in range(N):
        if i != j and arr[i][j] == 1:
            dic[i].append(j)

q = deque()
visited = [0] * N
q.append(plan[0]-1)
visited[plan[0]-1] = 1
while q:
    now = q.popleft()
    for i in dic[now]:
        if visited[i] == 0:
            q.append(i)
            visited[i] = 1


suc = True
for i in plan:
    if visited[i-1] == 0:
        suc = False
        break

if suc:
    print('YES')
else:
    print('NO')