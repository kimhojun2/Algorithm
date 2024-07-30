# 백준 1138 실버2

N = int(input())
line = [0]*N
lst = list(map(int, input().split()))

for i in range(N):
    now = lst[i]
    taller = 0
    for j in range(N):
        if taller < now and line[j] == 0:
            taller += 1

        elif taller == now:
            if line[j] == 0:
                line[j] = i + 1
                break

print(*line)