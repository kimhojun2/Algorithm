"()(((()())(())()))(())"

arr = list(input())
stack = []
stick = 0
top = ''
ans = 0
for now in arr:

    if not stick:
        stick += 1

    else:
        if top == '(':
            if now =='(':
                stick += 1
            else:
                stick -= 1
                ans += stick

        else:
            if now == ')':
                stick -= 1
                ans += 1
            else:
                stick += 1
    top = now

print(ans)