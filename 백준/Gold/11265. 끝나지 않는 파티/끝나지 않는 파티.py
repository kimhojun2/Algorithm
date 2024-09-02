import sys

input = sys.stdin.readline

N, M = map(int, input().split())

arr = []

for n in range(N):
    row = list(map(int, input().split()))
    arr.append(row)
    
for k in range(N):
    for i in range(N):
        for j in range(N):
            if arr[i][j] > arr[i][k] + arr[k][j]:
                arr[i][j] = arr[i][k] + arr[k][j]

for m in range(M):
    A, B, C = map(int, input().split())
    if arr[A - 1][B - 1] <= C:
        print('Enjoy other party')
    else:
        print('Stay here')