N = int(input())
dic = {}

cnt = 0
for n in range(N):
    cow, lr = map(int, input().split())
    if cow not in dic:
        dic[cow] = lr
    else:
        if dic[cow] != lr:
            cnt += 1
            dic[cow] = lr

print(cnt)