arr = []
cnt = 5
while cnt > 0 :
    now = input()
    arr.append(now)
    cnt -= 1

n = 0
while n < 15:
    for i in arr:
        l = len(i)
        if not n >= len(i):
            print(i[n], end='')
    n += 1