import sys

input = sys.stdin.readline

n = int(input())
arr = []
answer = ''
for i in range(n):
    arr.append(list(input()))


def solution(x, y, N):
    global answer
    color = arr[y][x]
    d = N // 2
    for i in range(y, y + N):
        for j in range(x, x + N):
            if color != arr[i][j]:
                answer += '('
                solution(x, y, d)
                solution(x + d, y, d)
                solution(x, y + d, d)
                solution(x + d, y + d, d)
                answer += ')'
                return
    answer += color


solution(0, 0, n)
print(answer)