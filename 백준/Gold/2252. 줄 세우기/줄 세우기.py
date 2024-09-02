import sys

input = sys.stdin.readline

N, M = map(int, input().split())

dict = {}

for _ in range(M):
    A, B = map(int, input().split())
    if B not in dict:
        dict[B] = [A]
    else:
        dict[B].append(A)

ans = []
visited = [0] * (N+1)
def func(num):
    for p in dict[num]:
        if not visited[p]:
            visited[p] = 1
            if p in dict:
                func(p)
            else:
                print(p, end=' ')

    print(num, end=' ')

if N == 1:
    print(1)
else:
    for i in dict:
        if not visited[i]:
            visited[i] = 1
            func(i)

    for n in range(1, N+1):
        if visited[n] == 0:
            print(n, end=' ')
#
#
# print(dict)
# print(visited)