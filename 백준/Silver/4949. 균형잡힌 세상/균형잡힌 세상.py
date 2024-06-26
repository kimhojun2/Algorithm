while True:
    sentence = input()
    if sentence == '.':
        break

    stack = []
    for i in sentence:
        if not stack:
            if i == ']' or i == ')':
                stack.append(i)
                break

            if i == '[' or i =='(':
                stack.append(i)

        else:
            if i == '[' or i =='(':
                stack.append(i)

            if i == ')':

                if stack[-1] == '[':
                    break

                elif stack[-1] == '(':
                    stack.pop()

            elif i == ']':
                if stack[-1] == '(':
                    break

                elif stack[-1] == '[':
                    stack.pop()
    if stack:
        print('no')
    else:
        print('yes')