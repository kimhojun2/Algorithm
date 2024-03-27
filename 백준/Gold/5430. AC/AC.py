from collections import deque


T = int(input())

for tc in range(T):
    control = list(input())
    N = int(input())
    if N == 0:
        arr = deque(input()[1:-1])


    else:
        arr = deque(map(int, input()[1:-1].split(',')))


    R_num = 0
    flag = False
    for c in control:
        if c == 'R':
            R_num += 1

        else:
            if N != 0:
                N -= 1
                if R_num % 2 == 0:
                    arr.popleft()
                else:
                    arr.pop()
            else:
                flag = True
                break

    if flag:
        print('error')
    else:
        if R_num % 2 == 0:
            print(str(list(arr)).replace(' ',''))
        else:
            arr.reverse()
            print(str(list(arr)).replace(' ', ''))