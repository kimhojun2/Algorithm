T = int(input())

for tc in range(T):
    N = int(input())


    cnt = 0
    K = N
    while K > 3:
        cnt += 1
        cnt += (K // 2)
        K -= 3

    print(cnt + K)