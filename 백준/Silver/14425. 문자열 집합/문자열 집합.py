import sys

input = sys.stdin.readline
N, M = map(int, input().split())
dic = {}
for n in range(N):
    now = input().rstrip()
    if now[0] not in dic:
        dic[now[0]] = [now]
    else:
        dic[now[0]].append(now)
cnt = 0
for m in range(M):
    check = input().rstrip()
    if check[0] in dic:
        if check in dic[check[0]]:
            cnt += 1

print(cnt)