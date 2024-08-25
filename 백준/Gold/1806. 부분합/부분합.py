N, S = map(int, input().split())
arr = list(map(int, input().split()))

l = 0
r = 0
total = 0
ans = float('inf')

while r < N:
    total += arr[r]
    r += 1

    while total >= S:
        ans = min(ans, r - l)
        total -= arr[l]
        l += 1

if ans == float('inf'):
    print(0)
else:
    print(ans)
