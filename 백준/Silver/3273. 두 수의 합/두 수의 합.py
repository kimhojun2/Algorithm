N = int(input())
arr = list(map(int, input().split()))
X = int(input())
arr.sort()
left = 0
right = N-1

cnt = 0
while left < right:
    if arr[left] + arr[right] == X:
       cnt +=1
       left += 1
       right -= 1

    elif arr[left] + arr[right] < X:
        left += 1

    else:
        right -= 1


print(cnt)