import sys

input = sys.stdin.readline

N = list(input().rstrip())
check = [0]*10
for n in N:
    now = int(n)
    if now == 6 or now == 9:
        if check[6] >= check[9]:
            check[9] += 1
        else:
            check[6] += 1
    else:
        check[now] += 1

print(max(check))