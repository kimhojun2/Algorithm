N = int(input())
lst = [0]
for i in range(N):
    now = int(input())
    lst.append(now)

# visited = [0]*(N+1)
ans = []
for i in range(1, N+1):
    visited = [0] * (N + 1)
    SUM = 0
    stack = []
    res = []
    res.append(i)
    visited[i] = 1
    stack.append(i)
    while stack:
        idx = stack.pop()
        value = lst[idx]
        SUM = SUM + idx - value
        if not visited[value]:
            stack.append(value)
            res.append(value)
            visited[value] = 1

    if SUM == 0:
        for item in res:
            if item not in ans:
                ans.append(item)

print(len(ans))
ans.sort()
for i in ans:
    print(i)
