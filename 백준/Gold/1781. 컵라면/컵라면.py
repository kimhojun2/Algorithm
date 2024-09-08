import heapq

N = int(input())

problems = []
for _ in range(N):
    deadline, ramen = map(int, input().split())
    problems.append((deadline, ramen))

problems.sort()

heap = []
for deadline, ramen in problems:
    heapq.heappush(heap, ramen)
    if len(heap) > deadline:
        heapq.heappop(heap)


print(sum(heap))
