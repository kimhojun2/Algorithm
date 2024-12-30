import heapq

T = int(input())

for tc in range(T):
    M = int(input())
    arr = []
    rows = (M // 10) + (1 if M % 10 > 0 else 0)
    for _ in range(rows):
        now = list(map(int, input().split()))
        arr.extend(now)

    i = 1
    ans = []
    while i <= len(arr):
        check = arr[:i]
        check.sort()
        ans.append(check[len(check) // 2])
        i += 2
    # print(arr)
    chunk_size = 10
    print(len(ans))
    for i in range(0, len(ans), chunk_size):
        print(*ans[i:i + chunk_size])