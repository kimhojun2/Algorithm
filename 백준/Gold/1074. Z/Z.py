import sys

input = sys.stdin.readline

N, r, c = map(int, input().split())


def division_check(r,c,y0,x0,N):
    global ans

    if N == 1:
        return

    L = N // 2

    if y0<=r<y0+L and x0+L<=c<x0+N:
        ans += L*L*1
        division_check(r, c,y0,x0+L,L)
        pass

    elif y0<=r<y0+L and x0<=c<x0+L:
        division_check(r, c,y0,x0, L)
        pass

    elif y0+L<= r< y0+N and x0<=c<x0+L:
        ans += L*L*2
        division_check(r, c,y0+L,x0, L)
        pass
    else:
        ans += L*L*3
        division_check(r, c,y0+L,x0+L,L)
        pass


ans = 0
if r == 0 and c == 0:
    print(ans)
else:
    division_check(r,c,0,0,2**N)
    print(ans)