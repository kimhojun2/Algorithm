N, M = map(int, input().split())
dic = {}
for i in range(N):
    now = input()
    if now not in dic:
        dic[now] = 1
cnt = 0
for j in range(M):
    bo = input()
    if bo in dic:
        dic[bo] += 1
        cnt += 1

answers = [key for key, value in dic.items() if value == 2]
answers.sort()
print(cnt)
for answer in answers:
    print(answer)