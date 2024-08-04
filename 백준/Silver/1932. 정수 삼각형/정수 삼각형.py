n = int(input())
lst = []
for i in range(n):
    if i == 0:
        now = [int(input())]
        lst.append(now)
        continue

    now = list(map(int, input().split()))

    lst.append(now)

for i in range(1, n):
    for j in range(i+1):
        if j == 0:
            lst[i][j] = lst[i-1][j] + lst[i][j]
        elif j == i:
            lst[i][j] = lst[i-1][j-1] + lst[i][j]
        else:
            lst[i][j] = max(lst[i-1][j] + lst[i][j], lst[i-1][j-1] + lst[i][j])

print(max(lst[n-1]))