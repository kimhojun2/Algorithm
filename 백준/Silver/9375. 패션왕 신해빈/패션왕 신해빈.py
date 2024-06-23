T = int(input())
for tc in range(T):
    N = int(input())
    wearing = {}
    for n in range(N):
        a, b = map(str, input().split())
        if b not in wearing:
            wearing[b] = 1
        else:
            wearing[b] += 1

    cnt = 1
    for j in wearing.values():
        cnt *= (j+1)

    print(cnt-1)