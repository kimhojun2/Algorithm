# 11899 괄호 끼워넣기

gs = input()

L = len(gs)

stack = 0
total = 0
for i in range(L):
    if i == 0:
        if gs[i] == ')':
            total += 1
        else:
            stack += 1

    else:
        if gs[i] == '(':
            stack += 1

        else:
            if stack == 0:
                total += 1
            else:
                stack -= 1

if stack:
    print(total + stack)
else:
    print(total)