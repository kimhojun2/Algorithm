import sys

input = sys.stdin.readline

N, M = map(int, input().split())
arr = [int(input()) for _ in range(M)]

left, right = 1, max(arr)
ans = 0

while left <= right:
    mid = (left + right) // 2
    cnt = 0

    for jewel in arr:
        cnt += jewel // mid
        if jewel % mid != 0:
            cnt += 1

    if cnt <= N:
        ans = mid
        right = mid - 1
    else:
        left = mid + 1

print(ans)
