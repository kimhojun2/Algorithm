import heapq

N = int(input())
arr = []
for i in range(N):
    s, e = map(int, input().split())
    arr.append((s,e))

arr.sort()
rooms = []
heapq.heappush(rooms, arr[0][1])
for i in range(1,N):
    s, e = arr[i]
    if rooms[0] <= s:
        heapq.heappop(rooms)

    heapq.heappush(rooms, e)

    
print(len(rooms))