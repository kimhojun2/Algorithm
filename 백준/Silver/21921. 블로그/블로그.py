N, X = map(int, input().split())
arr = list(map(int, input().split()))

# 첫 윈도우의 합 계산
current_sum = sum(arr[:X])
max_sum = current_sum
count = 1

for i in range(1, N - X + 1):
    current_sum = current_sum - arr[i - 1] + arr[i + X - 1]
    if current_sum > max_sum:
        max_sum = current_sum
        count = 1
    elif current_sum == max_sum:
        count += 1

if max_sum == 0:
    print("SAD")
else:
    print(max_sum)
    print(count)
