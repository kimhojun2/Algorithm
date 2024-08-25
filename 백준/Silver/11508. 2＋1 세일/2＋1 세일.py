N = int(input())
arr = []
for i in range(N):
    now = int(input())
    arr.append(now)

ans = sorted(arr, key=lambda x:-x)

cnt = 0
total = 0
sale = 0
for j in ans:
    if cnt == 2:
        cnt = 0
        total += sale
        sale = 0
    else:
        cnt += 1
        sale += j

if sale != 0:
    print(total + sale)
else:
    print(total)