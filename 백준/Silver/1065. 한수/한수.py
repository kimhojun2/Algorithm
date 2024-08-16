N = int(input())
cnt = 0
now = 0
for i in range(1, N+1):
    now = list(map(int, str(i)))
    if len(now) == 1:
        cnt += 1

    elif len(now) == 2:
        cnt += 1

    else:
        d = 0
        check = False
        for j in range(1, len(now)):
            if j == 1:
                d = now[0] - now[1]
                continue

            if d != now[j-1] - now[j]:
                check = True
                break

        if not check:
            cnt += 1

print(cnt)