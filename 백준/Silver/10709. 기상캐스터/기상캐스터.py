H, W = map(int, input().split())

arr = [list(input()) for _ in range(H)]


for i in range(H):
    now = -1
    for j in range(W):
        if arr[i][j] == 'c':
            now = j
            arr[i][j] = 0

        elif now == -1 and arr[i][j] == '.':
            arr[i][j] = -1

        else:
            arr[i][j] = j-now

for h in arr:
    print(*h)