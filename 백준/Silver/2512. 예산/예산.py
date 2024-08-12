N = int(input())
arr = list(map(int, input().split()))
limit = int(input())

left = 0
right = max(arr)
ans = 0
while left <= right:
    mid = (left + right) // 2
    total = 0
    for i in arr:
        if i > mid:
            total += mid
        else:
            total += i

    if total <= limit:
        ans = mid
        left = mid + 1
    else:
        right = mid - 1

print(ans)