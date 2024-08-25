N = int(input())
ans = 0
while True:
    if N%5 == 0:
        ans += N//5
        break

    else:
        N -= 2
        ans += 1

    if N < 0:
        break

if N < 0:
    print(-1)
else:
    print(ans)