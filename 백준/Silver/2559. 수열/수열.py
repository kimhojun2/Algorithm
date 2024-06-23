N, K = map(int, input().split())

lst = list(map(int, input().split()))


max_sum = sum(lst[:K])
now_sum = sum(lst[:K])
now = 0
for i in range(K, N):
    new_sum = now_sum - lst[now] + lst[i]
    if new_sum > max_sum:
        max_sum = new_sum
    now += 1
    now_sum = new_sum

print(max_sum)