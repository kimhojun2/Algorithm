import sys

input = sys.stdin.readline

N, H = map(int, input().split())

changes = [0] * (H + 1)

for i in range(N):
    high = int(input())
    if i % 2 == 0:
        changes[H - high] += 1
    else:
        changes[0] += 1
        changes[high] -= 1


heights = [0] * H
heights[0] = changes[0]
for i in range(1, H):
    heights[i] = heights[i - 1] + changes[i]

min_break = min(heights)
cnt = heights.count(min_break)

print(min_break, cnt)
