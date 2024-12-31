import sys

input = sys.stdin.readline

N, M, y, x, K = map(int, input().split())
arr = [list(map(int, input().split())) for _ in range(N)]
Orders = list(map(int, input().split()))


def Rolling_Dice(order):
    if order == 1:
        temp1 = dice[1]
        temp2 = dice[4]
        dice[1] = dice[3]
        dice[3] = dice[6]
        dice[4] = temp1
        dice[6] = temp2


    elif order == 2:
        temp1 = dice[1]
        temp2 = dice[3]
        dice[1] = dice[4]
        dice[3] = temp1
        dice[4] = dice[6]
        dice[6] = temp2


    elif order == 3:
        temp1 = dice[1]
        temp2 = dice[5]
        dice[1] = dice[2]
        dice[2] = dice[6]
        dice[5] = temp1
        dice[6] = temp2

    else:
        temp1 = dice[1]
        temp2 = dice[2]
        dice[1] = dice[5]
        dice[2] = temp1
        dice[5] = dice[6]
        dice[6] = temp2


def limit_check(order,y,x):
    if order == 1:
        ny, nx = y, x+1
    elif order == 2:
        ny, nx = y, x-1
    elif order == 3:
        ny, nx = y-1, x
    else:
        ny, nx = y+1, x

    if 0<= ny < N and 0<= nx < M:
        return (ny, nx)
    else:
        return False


dice = [0,0,0,0,0,0,0]
for order in Orders:
    T = limit_check(order,y,x)
    if T:
        y, x = T
        Rolling_Dice(order)
        if arr[y][x] == 0:
            arr[y][x] = dice[1]
            print(dice[6])
        else:
            dice[1] = arr[y][x]
            arr[y][x] = 0
            print(dice[6])



