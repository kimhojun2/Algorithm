import sys

input = sys.stdin.readline
N = int(input())
n = sorted(list(set(map(int, input().split()))))

M = int(input())
m = list(map(int, input().split()))

for i in m:
    start = 0
    end = len(n)-1
    result = 0
    while end >= start:
        middle = (start + end)//2
        if n[middle] == i:
            result = 1
            break
        elif n[middle] > i:
            end = middle -1
        else:
            start = middle + 1
    print(result)