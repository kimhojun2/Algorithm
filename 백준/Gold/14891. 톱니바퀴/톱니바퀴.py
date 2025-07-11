from collections import deque

def check_right(check, dir, rotates):
    if check >= 3:
        return
    if now[check][1] != now[check+1][0]:
        rotates.append((check+1, -dir))
        check_right(check+1, -dir, rotates)

def check_left(check, dir, rotates):
    if check <= 0:
        return
    if now[check][0] != now[check-1][1]:
        rotates.append((check-1, -dir))
        check_left(check-1, -dir, rotates)

lst = [deque(input()) for _ in range(4)]

K = int(input())

for _ in range(K):
    n, d = map(int, input().split())
    now = [[lst[i][6], lst[i][2]] for i in range(4)]

    rotates = [(n-1, d)]
    check_right(n-1, d, rotates)
    check_left(n-1, d, rotates)

    for idx, dir in rotates:
        lst[idx].rotate(dir)

ans = 0
for i in range(4):
    if lst[i][0] == '1':
        ans += 2**i

print(ans)
