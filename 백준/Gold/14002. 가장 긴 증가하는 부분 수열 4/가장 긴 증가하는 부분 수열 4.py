N = int(input())
arr = list(map(int, input().split()))

def sol(arr):
    dp = [1] * N
    prev = [-1] * N  # 이전 인덱스를 추적할 배열

    for i in range(1, N):
        for j in range(i):
            if arr[j] < arr[i] and dp[i] < dp[j] + 1:
                dp[i] = dp[j] + 1
                prev[i] = j  # 이전 인덱스를 기록

    # LIS 길이와 끝나는 인덱스를 찾음
    max_len = max(dp)
    idx = dp.index(max_len)

    # LIS 재구성
    lis = []
    while idx != -1:
        lis.append(arr[idx])
        idx = prev[idx]

    lis.reverse()  # 역순이므로 뒤집기
    return max_len, lis

length, sequence = sol(arr)
print(length)  # LIS의 길이
print(*sequence)  # LIS
