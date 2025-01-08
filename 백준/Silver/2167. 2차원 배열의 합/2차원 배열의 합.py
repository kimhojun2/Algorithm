N, M = map(int, input().split())
arr = [list(map(int, input().split())) for _ in range(N)]
prefix_sum = [[0]*M for _ in range(N)]
K = int(input())

for i in range(N):
    for j in range(M):
        prefix_sum[i][j] = arr[i][j]
        if i > 0:
            prefix_sum[i][j] += prefix_sum[i-1][j]

        if j > 0:
            prefix_sum[i][j] += prefix_sum[i][j-1]

        if i>0 and j>0:
            prefix_sum[i][j] -= prefix_sum[i-1][j-1]



for tc in range(K):
    i,j,x,y = map(int, input().split())
    if i == x and j == y:
        print(arr[i-1][j-1])

    else:
        if i == 1 and j == 1:
            print(prefix_sum[x-1][y-1])

        elif i == 1:
            print(prefix_sum[x-1][y-1] - prefix_sum[x-1][j-2])

        elif j == 1:
            print(prefix_sum[x-1][y-1]-prefix_sum[i-2][y-1])

        else:
            print(prefix_sum[x-1][y-1]-prefix_sum[x-1][j-2]-prefix_sum[i-2][y-1] + prefix_sum[i-2][j-2])