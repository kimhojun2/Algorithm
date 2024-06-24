N = int(input())

cnt = 0
for n in range(N):
    word = input()
    stack = []
    for i in word:
        if not stack:
            stack.append(i)

        elif stack[-1] == i:
            stack.pop()

        else:
            stack.append(i)

    if not stack:
        cnt += 1

print(cnt)