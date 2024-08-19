import sys
input = sys.stdin.readline
N = int(input())
dic = {}
for i in range(N):
    a, b = map(str, input().rstrip().split('.'))
    if b not in dic:
        dic[b] = 1
        continue
    dic[b] += 1

answer = sorted([(key, value) for key, value in dic.items()], key=lambda x:x)
for c,d in answer:
    print(c,d)