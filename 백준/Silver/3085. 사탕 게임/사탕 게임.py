# 3085

# 확인하는 함수
def check(cnady):
    max_cnt = 1
    for i in range(N):
        cnt = 1
        for j in range(1, N):
            if candy[i][j] == candy[i][j-1]:
                cnt += 1
            else:
                cnt = 1
            max_cnt = max(max_cnt, cnt)

        cnt = 1
        for j in range(1, N):
            if cnady[j][i] == cnady[j-1][i]:
                cnt += 1
            else:
                cnt = 1
            max_cnt = max(max_cnt, cnt)

    return max_cnt


N = int(input())
candy = [list(input()) for _ in range(N)]
ans = 0

for i in range(N):
    for j in range(N):
        if j + 1 < N:
            candy[i][j], candy[i][j+1] = candy[i][j+1], candy[i][j]
            cnt = check(candy)
            ans = max(ans, cnt)
            candy[i][j], candy[i][j+1] = candy[i][j+1], candy[i][j]

        if i + 1 < N:
            candy[i][j], candy[i+1][j] = candy[i+1][j], candy[i][j]
            cnt = check(candy)
            ans = max(ans, cnt)
            candy[i][j], candy[i+1][j] = candy[i+1][j], candy[i][j]

print(ans)
