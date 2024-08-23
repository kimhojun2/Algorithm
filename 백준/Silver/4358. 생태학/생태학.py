import sys
input = sys.stdin.readline

dic = {}
total = 0
while True:
    tree = input().rstrip()
    if not tree:
        break

    if tree not in dic:
        dic[tree] = 1
    else:
        dic[tree] += 1

    total += 1

ans_dic = dict(sorted(dic.items()))
for key, value in ans_dic.items():
    percentage = (value / total) * 100
    print(f"{key} {percentage:.4f}")