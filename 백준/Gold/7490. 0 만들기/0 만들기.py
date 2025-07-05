def calc(ans):
    expr = "".join(ans).replace(" ", "")

    total = 0
    num = ''
    sign = 1
    for c in expr:
        if c == '+':
            total += sign * int(num)
            num = ''
            sign = 1
        elif c == '-':
            total += sign * int(num)
            num = ''
            sign = -1
        else:
            num += c
    total += sign * int(num)
    return total


def backtracking(idx, ans):

    if idx == N-1:
        s = calc(ans)
        if s == 0:
            print("".join(ans))
        return

    now = lst[idx+1]
    for operator in range(3):
        # + 연산
        if operator == 0:
            before = ans[-1]
            ans[-1] += " "
            ans[-1] += str(now)
            backtracking(idx+1,ans)
            ans[-1] = before


        # - 연산
        elif operator == 1:
            ans.extend(['+', str(now)])
            backtracking(idx + 1, ans)
            ans.pop()
            ans.pop()

        # 붙이기 연산
        else:
            ans.extend(['-', str(now)])
            backtracking(idx+1,ans)
            ans.pop()
            ans.pop()


    return


T = int(input())

for tc in range(T):
    N = int(input())
    lst = [i for i in range(1, N+1)]

    backtracking(0,['1'])
    print()

