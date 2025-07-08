def solution(A, B):
    cnt = 1
    while B > A:
        if B % 2 == 0:
            B //= 2
        elif str(B)[-1] == '1':
            B = int(str(B)[:-1])
        else:
            return -1
        cnt += 1

    return cnt if B == A else -1

A, B = map(int, input().split())
print(solution(A, B))
