N = int(input())

arr = list(map(int, input().split()))

candidate = []

for i in range(1,int(N*0.5)+1):
    if N % i == 0:
        candidate.append(i)


possible = False
for cut in candidate:
    init = arr[:cut]
    S = max(init) + min(init)
    stop = True
    for i in range(cut,N,cut):
        now = arr[i:i+cut]
        now_S = max(now) + min(now)
        if S != now_S:
            stop = False
            break

    if stop:
        possible = True
        break

print(1 if possible else 0)