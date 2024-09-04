import sys
from collections import deque

input = sys.stdin.readline

arr = list(input().rstrip())

q = deque()
for i in arr:
    if i == '(' or i == '[':
        q.append(i)
    elif i == ')':
        if not q or q[-1] == '[':
            print(0)
            sys.exit()
        if q[-1] == '(':
            q.pop()
            q.append(2)
        else:
            total = 0
            while q and (type(q[-1]) is int):
                total += q.pop()
            if not q or q[-1] != '(':
                print(0)
                sys.exit()
            q.pop()
            q.append(total * 2)
    elif i == ']':
        if not q or q[-1] == '(':
            print(0)
            sys.exit()
        if q[-1] == '[':
            q.pop()
            q.append(3)
        else:
            total = 0
            while q and (type(q[-1]) is int):
                total += q.pop()
            if not q or q[-1] != '[':
                print(0)
                sys.exit()
            q.pop()
            q.append(total * 3)


result = 0
while q:
    value = q.popleft()
    if type(value) is int:
        result += value
    else:  
        print(0)
        sys.exit()

print(result)
