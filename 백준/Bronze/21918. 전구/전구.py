N, M = map(int, input().split())
arr = list(map(int, input().split()))

for m in range(M):
    a,b,c = map(int, input().split())

    if a == 1:
        arr[b-1] = c

    elif a == 2:
        for i in range(b-1, c):
            if arr[i] == 1:
                arr[i] = 0
            else:
                arr[i] = 1

    elif a == 3:
        for i in range(b-1,c):
            arr[i] = 0

    else:
        for i in range(b-1,c):
            arr[i] = 1

print(*arr)