import sys
import heapq

input = sys.stdin.readline

N = int(input())
dp = [0] * 8001
v1 = 0
v2_mid = []
v3 = 0
v3_li = []
v4_min = 4000
v4_max = -4000

for i in range(N):
    now = int(input())
    v2_mid.append(now)
    v1 += now
    dp[4000 + now] += 1

    if dp[4000 + now] > v3:
        v3_li = [now]
        v3 = dp[4000 + now]
    elif dp[4000 + now] == v3:
        v3_li.append(now)

    v4_min = min(v4_min, now)
    v4_max = max(v4_max, now)

v2_mid.sort()
v3_li.sort()

print(round(v1 / N))  # v1
print(v2_mid[N // 2])  # v2

if len(v3_li) > 1:  # v3
    print(v3_li[1])
else:
    print(v3_li[0])

print(v4_max - v4_min)  # v4
