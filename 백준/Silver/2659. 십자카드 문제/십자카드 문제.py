from collections import deque

def check(num):
    now = int(''.join(num))
    Min = now
    i = 0
    while i < 3:
        num.rotate(-1)
        next = int(''.join(num))
        if next < Min:
            Min = next
        i += 1

    if Min == now:
        return 1
    else:
        return 0

def first(num):
    now = int(''.join(num))
    Min = now
    i = 0
    while i < 3:
        num.rotate(-1)
        next = int(''.join(num))
        if next < Min:
            Min = next
        i += 1

    return Min





number = first(deque(list(input().split())))

cnt = 0
for k in range(1111, number):
    num = deque(list(str(k)))
    ans = check(num)
    if ans == 1:
        cnt += 1


print(cnt+1)