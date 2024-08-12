N = int(input())
arr = []
for i in range(N):
    now = list(map(int, input().split()))
    arr.append(now)

check = [[0]*N for _ in range(N)]
for i in range(N):
    for j in range(5):
        for k in range(N):
            if arr[i][j] == arr[k][j]:
                check[i][k] = 1


ans = [0]*N
for i in range(N):
    a = check[i]
    ans[i] = a.count(1)

print(ans.index(max(ans))+1)


