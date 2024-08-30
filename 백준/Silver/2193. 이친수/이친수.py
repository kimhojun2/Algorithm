N = int(input())

cnt0 = 0
cnt1 = 0

for i in range(N):
    if i == 0:
        cnt1 += 1
    else:
        now_0 = cnt0 + cnt1
        now_1 = cnt0
        cnt0 = now_0
        cnt1 = now_1

print(cnt0+cnt1)