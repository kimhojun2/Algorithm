import sys
import heapq

input = sys.stdin.readline

N = int(input())

arr = list(map(int, input().split()))

heap = []

for idx, value in enumerate(arr):
    new = (value, idx)
    heapq.heappush(heap,new)


back_value = -float('inf')
new_idx = -1
ans= []
while heap:
    v, n = heapq.heappop(heap)
    if v > back_value:
        new_idx += 1
        back_value = v
    ans.append((n, new_idx))

ans.sort()

for i in ans:
    print(i[1], end=' ')