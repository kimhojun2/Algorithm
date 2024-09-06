import sys

input = sys.stdin.readline

N = int(input())
M = int(input())

def B(start):
    stack = [start]
    visited = [0] * (N + 1)
    visited[start] = 1
    while stack:
        now = stack.pop()
        for i in big.get(now,{}):
            if visited[i] == 0:
                stack.append(i)
                visited[i] = 1

    return visited[1:]


def S(start):
    stack = [start]
    visited = [0] * (N + 1)
    visited[start] = 1
    while stack:
        now = stack.pop()
        for i in small.get(now, {}):
            if visited[i] == 0:
                stack.append(i)
                visited[i] = 1

    return visited[1:]


small = {}
big = {}
for _ in range(M):
    a, b = map(int, input().split())
    if a not in big:
        big[a] = [b]
    else:
        big[a].append(b)

    if b not in small:
        small[b] = [a]

    else:
        small[b].append(a)

# print('big', big)
# print('small',small)
for n in range(1, N+1):
    BIG = B(n)
    SMALL = S(n)
    ans = 0
    for i in range(N):
        if BIG[i] + SMALL[i] == 0:
            ans += 1
    print(ans)