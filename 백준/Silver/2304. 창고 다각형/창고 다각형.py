# 백준 2304 실버2
import sys
input = sys.stdin.readline

N = int(input())

lst = []
high = 0
idx = 0
for i in range(N):
    L, H = map(int, input().split())
    if H > high:
        high = H
    lst.append((L,H))

lst2 = sorted(lst, key=lambda x: x[0])

idx_l = 0
for i in range(N):
    l, h = lst2[i][0], lst2[i][1]
    if h == high:
        idx = i
        idx_l = l
now_L = 0
now_H = 0
area = 0
for i in range(0, idx):
    next_L, next_H = lst2[i][0], lst2[i][1]

    if i == 0:
        now_L = next_L
        now_H = next_H
        continue

    if now_H < next_H:
        x = next_L - now_L
        area += x * now_H

        now_L = next_L
        now_H = next_H
area += (idx_l - now_L) * now_H
now_L = 0
now_H = 0

for i in range(N-1, idx, -1):
    next_L, next_H = lst2[i][0], lst2[i][1]

    if i == 0:
        now_L = next_L
        now_H = next_H
        continue

    if now_H < next_H:
        x = now_L - next_L
        area += x * now_H

        now_L = next_L
        now_H = next_H

area += (now_L-idx_l) * now_H
area += high
print(area)
# print(idx)
# print(high)
# print(idx_l)