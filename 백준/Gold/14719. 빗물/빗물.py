# 백준 14719 골드 5

H, W = map(int, input().split())

left = 0
right = 0
rain = 0
blocks = list(map(int, input().split()))
for i in range(W):
    block = blocks[i]
    if i == 0 or i == W-1:
        continue

    leftside = blocks[0:i]
    rightside = blocks[i+1:]
    left = max(leftside)
    right = max(rightside)

    if left >= right:
        now = right - block
    else:
        now = left - block

    if now >= 0:
        rain += now


print(rain)