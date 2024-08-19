import sys
input = sys.stdin.readline
N, M = map(int, input().rstrip().split())
dic = {}

for i in range(N):
    now = input().rstrip()
    l = len(now)
    if l < M:
        continue
    if now not in dic:
        dic[now] = 1
    else:
        dic[now] += 1

answer = sorted(dic.keys(), key=lambda x: (-dic[x], -len(x), x))
for ans in answer:
    print(ans)