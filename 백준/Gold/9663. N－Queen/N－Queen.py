import sys

input = sys.stdin.readline
N = int(input())
ans = 0

cols = [0] * N
diag1 = [0] * (2 * N - 1)
diag2 = [0] * (2 * N - 1)

def solve(y):
    global ans
    if y == N:
        ans += 1
        return

    for x in range(N):
        if cols[x] or diag1[y + x] or diag2[y - x + (N - 1)]:
            continue

        cols[x] = diag1[y + x] = diag2[y - x + (N - 1)] = 1
        solve(y + 1)
        cols[x] = diag1[y + x] = diag2[y - x + (N - 1)] = 0

solve(0)
print(ans)