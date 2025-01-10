import sys

input = sys.stdin.readline

M = int(input())

dic = {i:False for i in range(1,21)}

for m in range(M):
    order = list(input().split())
    if order[0] == "add":
        num = int(order[1])
        if not dic[num]:
            dic[num] = True

    elif order[0] == "remove":
        num = int(order[1])
        if dic[num]:
            dic[num] = False

    elif order[0] == "check":
        num = int(order[1])
        if dic[num]:
            print(1)
        else:
            print(0)

    elif order[0] == "toggle":
        num = int(order[1])
        if dic[num]:
            dic[num] = False
        else:
            dic[num] = True

    elif order[0] == "all":
        for key in dic.keys():
            dic[key] = True

    else:
        for key in dic.keys():
            dic[key] = False