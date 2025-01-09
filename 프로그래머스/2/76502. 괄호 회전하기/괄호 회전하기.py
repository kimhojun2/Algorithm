def solution(s):
    from collections import deque

    def check(arr):
        stack = []
        for i in arr:
            if i in '([{':
                stack.append(i)
            else:
                if not stack:
                    return 0
                top = stack.pop()
                if top == '(' and i != ')':
                    return 0
                if top == '[' and i != ']':
                    return 0
                if top == '{' and i != '}':
                    return 0
                    
        if stack:
            return 0

        return 1
    
    
    answer = 0
    q = deque(s)
    L = len(s)
    for i in range(L):
        if check(q):
            answer += 1
        q.rotate(-1)
        
    return answer