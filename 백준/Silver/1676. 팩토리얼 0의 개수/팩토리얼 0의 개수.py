from math import factorial

N = int(input())

if N == 0:
    print(0)
else:
    fac = factorial(N)
    cnt = 0
    while True:
        if fac == 0:
            print(cnt)
            break

        now = fac%10
        if now == 0:
            cnt +=1
            fac //= 10

        if now != 0:
            print(cnt)
            break
