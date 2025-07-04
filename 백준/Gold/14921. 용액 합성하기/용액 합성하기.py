N = int(input())
lst = list(map(int, input().split()))
lst.sort()

left, right = 0, N - 1
ans = lst[left] + lst[right]

while left < right:
    now = lst[left] + lst[right]

    if abs(now) < abs(ans):
        ans = now

    if now < 0:
        left += 1
    elif now > 0:
        right -= 1
    else:
        ans = 0
        break

print(ans)
