def backtracking(n):
    global ans
    if n == N:
        ans += 1
        return

    for j in range(N):
        if v1[j] == v2[n+j] == v3[n-j] == 0:
            v1[j] = v2[n + j] = v3[n - j] = 1
            backtracking(n+1)
            v1[j] = v2[n + j] = v3[n - j] = 0


N = int(input())
ans = 0
v1 = [0]*N
v2 = [0]*(2*N)
v3 = [0]*(2*N)

backtracking(0)

print(ans)