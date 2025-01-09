N = int(input())

arr = [list(map(int, input())) for _ in range(N)]

di = [0,0,1,-1]
dj = [1,-1,0,0]

def dfs(i,j):
    global cnt
    arr[i][j] = 0
    cnt += 1
    for d in range(4):
        ni, nj = i +di[d], j+dj[d]
        if 0<=ni<N and 0<=nj<N:
            if arr[ni][nj] == 1:
                dfs(ni,nj)


ans = []
for y in range(N):
    for x in range(N):
        if arr[y][x] == 1:
            cnt = 0
            dfs(y,x)
            ans.append(cnt)

ans.sort()
print(len(ans))
for a in ans:
    print(a)