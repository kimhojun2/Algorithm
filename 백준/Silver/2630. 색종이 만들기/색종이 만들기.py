import sys

input = sys.stdin.readline

N = int(input())
arr = [list(map(int, input().split())) for _ in range(N)]

ans = []

def division_check(y,x,N):
    color = arr[y][x]
    next = N//2
    for i in range(y,y+N):
        for j in range(x,x+N):
            if arr[i][j] != color:
                division_check(y,x,next)
                division_check(y+next,x,next)
                division_check(y,x+next,next)
                division_check(y+next,x+next,next)
                return

    if color == 0:
        ans.append(0)
    else:
        ans.append(1)


division_check(0,0,N)

print(ans.count(0))
print(ans.count(1))