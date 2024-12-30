import sys
import heapq

input = sys.stdin.readline

N = int(input())
lectures = []

for _ in range(N):
    n, s, e = map(int, input().split())
    heapq.heappush(lectures, (s, e))

rooms = []
while lectures:
    s, e = heapq.heappop(lectures)
    if rooms and rooms[0] <= s:
        heapq.heappop(rooms)
    heapq.heappush(rooms, e)

print(len(rooms))
