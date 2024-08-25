N = int(input())
M = int(input())
arr = list(map(int, input().split()))
arr.sort()
l = 0
r = N-1
cnt = 0
while l < r:
    if arr[l] + arr[r] == M:
        cnt += 1
        l += 1
        r -= 1

    elif arr[l] + arr[r] > M:
        r -= 1

    else:
        l += 1

print(cnt)