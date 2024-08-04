# letter = list(input())
import sys
input = sys.stdin.readline
le = input().strip()
boom = input().strip()
b = len(boom)
ans = []

for i in range(len(le)):
    ans.append(le[i])

    if ''.join(ans[-b:]) == boom:
        for i in range(b):
            ans.pop()

if not ans:
    print('FRULA')
else:
    print(''.join(ans))