from collections import deque

N = int(input())

cars_in = deque()
for i in range(N):
    cars_in.append(input())
cnt = 0
cars_out = deque()
for j in range(N):
    cars_out.append(input())


for i in range(N-1, -1, -1):
    now = cars_in[i]
    # print(now, i)
    out_idx = cars_out.index(now)
    if i != out_idx:
        cnt += 1
    cars_out.remove(now)

print(cnt)