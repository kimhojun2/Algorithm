def binary_search(lis, left, right, target):
    while left < right:
        mid = (left + right) // 2
        if lis[mid] < target:
            left = mid + 1
        else:
            right = mid
    return right

def lis_length(arr):
    n = len(arr)
    lis = [0] * n  # LIS를 저장할 배열
    length = 0  # LIS의 길이

    for i in range(n):
        if length == 0 or lis[length - 1] < arr[i]:
            lis[length] = arr[i]
            length += 1
        else:
            pos = binary_search(lis, 0, length, arr[i])  # 직접 구현한 이분 탐색
            lis[pos] = arr[i]

    return length

# 입력 및 실행
n = int(input())
arr = list(map(int, input().split()))
print(lis_length(arr))
