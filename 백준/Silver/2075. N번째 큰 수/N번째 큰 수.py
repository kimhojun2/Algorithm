import heapq

heap = []
N = int(input())

for i in range(N):
    nums = map(int, input().split())

    for num in nums:
        if len(heap) < N:
            heapq.heappush(heap, num)
        else:
            if heap[0] < num:
                heapq.heappop(heap)
                heapq.heappush(heap, num)

print(heap[0])