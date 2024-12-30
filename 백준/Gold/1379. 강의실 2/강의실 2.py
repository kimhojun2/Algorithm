import heapq
import sys

input = sys.stdin.readline

N = int(input())
lectures = []

for _ in range(N):
    n, s, e = map(int, input().split())
    heapq.heappush(lectures, (s, e, n))

num = {i:0 for i in range(1,N+1)}
rooms = []
idx = 1
while lectures:
    s, e, n = heapq.heappop(lectures)
    new_room = True
    if rooms and rooms[0][0] <= s:
        E, idxx = heapq.heappop(rooms)
        heapq.heappush(rooms, (e,idxx))
        num[n] = idxx
        continue

    heapq.heappush(rooms, (e,idx))
    num[n] = idx
    idx += 1


print(len(rooms))

for i in range(1,N+1):
    print(num[i])
