N, K = map(int, input().split())

arr = []
min_level = float('inf')
for i in range(N):
    now = int(input())
    arr.append(now)
    if min_level > now:
        min_level = now

def binary_search():
    left = min_level
    right = min_level + K
    ans = 0

    while left <= right:
        mid = (left + right) // 2

        total = 0
        for lev in arr:
            if mid > lev:
                total += (mid-lev)

        if total <= K:
            left = mid +1
            ans = max(ans, mid)

        else:
            right = mid - 1

    print(ans)

binary_search()

