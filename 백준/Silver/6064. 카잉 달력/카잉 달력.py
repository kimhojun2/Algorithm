def find_max(a,b):
    ans = 0
    r = min(a,b)
    for i in range(r,0,-1):
        if a%i == 0 and b%i ==0:
            ans = i
            break

    return ans*(N//ans)*(M//ans)


def calendar(limit, small, large, s, l):
    if small == large:
        return s if s == l else -1

    current = s
    while current <= limit:
        if (current - l) % large == 0:
            return current
        current += small

    return -1


T = int(input())

for tc in range(T):
    M,N,x,y = map(int, input().split())
    limit = find_max(N,M)
    if M<=N:
        ans = calendar(limit,M,N,x,y)
    else:
        ans = calendar(limit,N,M,y,x)
    print(ans)