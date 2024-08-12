import sys

input = sys.stdin.readline

N = int(input())
ans = list(map(int, input().split()))
ans.sort()
M = int(input())
cards = list(map(int, input().split()))

for card in cards:
    left, right, flage = 0, N-1, False
    while left <= right:
        mid = (left + right) // 2
        if ans[mid] > card:
            right = mid - 1
        elif ans[mid] < card:
            left = mid + 1
        else:
            flage = True
            break

    if flage:
        print(1, end=' ')
    else:
        print(0, end=' ')

