import sys
import heapq

input = sys.stdin.readline
N = int(input())
arr = []
for n in range(N):
    start, end = map(int, input().split())
    arr.append((start, end))

arr.sort()
q = [arr[0][1]]
for i in range(1,N):
    if q[0] <= arr[i][0]:
        heapq.heappop(q)

    heapq.heappush(q, arr[i][1])

print(len(q))