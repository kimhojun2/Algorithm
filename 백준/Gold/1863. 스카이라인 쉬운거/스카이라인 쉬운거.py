n = int(input())

s = []
cnt = 0
for i in range(n):
    x, y = map(int, input().split())

    if not s:
        if y == 0: continue
        s.append(y)

    else:
        while s and s[-1] > y:
            s.pop()
            cnt += 1

        if not s or s[-1] < y:
            if y == 0: continue
            s.append(y)


print(cnt + len(s))