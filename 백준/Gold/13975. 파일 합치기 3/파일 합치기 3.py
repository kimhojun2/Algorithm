import heapq

T = int(input())

for tc in range(T):
    K = int(input())
    arr = list(map(int, input().split()))
    heapq.heapify(arr)

    ans = 0
    while len(arr) > 1:
        A = heapq.heappop(arr)
        B = heapq.heappop(arr)
        new = A + B
        heapq.heappush(arr, new)
        ans += new

    print(ans)