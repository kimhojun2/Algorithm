import sys
from collections import Counter

input = sys.stdin.readline

T = int(input())
n = int(input())
A = list(map(int, input().split()))
m = int(input())
B = list(map(int, input().split()))

def get_all_partial_sums(arr):
    result = []
    for i in range(len(arr)):
        sum_ = 0
        for j in range(i, len(arr)):
            sum_ += arr[j]
            result.append(sum_)
    return result

A_sums = get_all_partial_sums(A)
B_sums = get_all_partial_sums(B)

B_counter = Counter(B_sums)

answer = 0
for a in A_sums:
    answer += B_counter[T - a]

print(answer)