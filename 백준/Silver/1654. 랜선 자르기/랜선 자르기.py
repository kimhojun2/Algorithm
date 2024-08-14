K, N = map(int, input().split())

MAX_LAN = 0
lans = []

for i in range(K):
    now = int(input())
    if now > MAX_LAN:
        MAX_LAN = now
    lans.append(now)
    # print(now)

left = 1
right = MAX_LAN
ans = 0
while left <= right:
    mid = (left+right) // 2
    cnt = 0
    for i in lans:
        cnt += (i // mid)

    if cnt < N:
        right = mid - 1

    else:
        left = mid + 1

print(right)