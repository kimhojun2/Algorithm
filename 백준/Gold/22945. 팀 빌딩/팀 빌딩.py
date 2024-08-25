N = int(input())
arr = list(map(int, input().split()))


l = 0
r = N-1
ans = 0
while l+1 < r:
    ans = max(ans, (r-l-1)*min(arr[r],arr[l]))

    if arr[l] < arr[r]:
        l += 1
    else:
        r -= 1

print(ans)